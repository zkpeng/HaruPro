//
// Created by ZKP on 2018/10/8.
//

#include <jni.h>
#include <hpdf_types.h>
#include <hpdf_doc.h>
#include <hpdf.h>
#include <string>
#include <memory.h>

extern "C"
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data) {
    printf("ERROR: error_no=%04X, detail_no=%d\n",
           (unsigned int) error_no, (int) detail_no);
//    throw std::exception (); /* throw exception on error */
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_zkp_inc_hpdfpro_MainActivity_generatePdf(JNIEnv *env, jobject instance, jstring txt,
                                                  jint txtsize, jfloat space, jboolean lock) {
    // TODO
    HPDF_Doc pdf;
    pdf = HPDF_New(error_handler, NULL); /* set error-handler */
    if (!pdf) {
        printf("error: cannot create PdfDoc object\n");
        return 1;
    }
    /* set compression mode */
    HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
    /* set page mode to use outlines. */
    HPDF_SetPageMode(pdf, HPDF_PAGE_MODE_USE_OUTLINE);
    /* set password */
    if (lock) {
        HPDF_SetPassword(pdf, "owner", "user");
    }
    HPDF_Page page_1;
    page_1 = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page_1, HPDF_PAGE_SIZE_B5, HPDF_PAGE_LANDSCAPE);
    HPDF_Page_BeginText(page_1);
    HPDF_Font font;
    font = HPDF_GetFont(pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize(page_1, font, txtsize);
    HPDF_Page_SetCharSpace(page_1, space);
    HPDF_Page_MoveTextPos(page_1, 10, 400);
    const char *cppMsg = env->GetStringUTFChars(txt, JNI_FALSE);
    HPDF_Page_ShowText(page_1, cppMsg);
    env->ReleaseStringUTFChars(txt, cppMsg);
    HPDF_Page_EndText(page_1);
    try {
        HPDF_SaveToFile(pdf, "/sdcard/test.pdf");
    } catch (...) {
        HPDF_Free(pdf);
        return 1;
    }
    HPDF_Free(pdf);
    return 0;
}