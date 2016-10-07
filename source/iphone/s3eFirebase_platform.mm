/*
 * iphone-specific implementation of the s3eFirebase extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eFirebase_internal.h"
#import "FIRApp.h"

s3eResult s3eFirebaseInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eFirebaseTerminate_platform()
{ 
}

void s3eFirebaseInitialize_platform()
{
    [FIRApp configure];
}
