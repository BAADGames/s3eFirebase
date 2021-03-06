/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eFirebase_autodefs.h"
#include "s3eEdk.h"
#include "s3eFirebase.h"
//Declarations of Init and Term functions
extern s3eResult s3eFirebaseInit();
extern void s3eFirebaseTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_TVOS ||defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void s3eFirebaseInitialize_wrap()
{
    IwTrace(FIREBASE_VERBOSE, ("calling s3eFirebase func on main thread: s3eFirebaseInitialize"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFirebaseInitialize, 0);
}
#define s3eFirebaseInitialize s3eFirebaseInitialize_wrap


#endif

void s3eFirebaseRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[1];
    funcPtrs[0] = (void*)s3eFirebaseInitialize;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[1] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("s3eFirebase", funcPtrs, sizeof(funcPtrs), flags, s3eFirebaseInit, s3eFirebaseTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eFirebaseStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eFirebaseRegisterExt;
    return 0;
}

int g_s3eFirebaseVal = s3eFirebaseStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eFirebaseRegisterExt();
}
#endif

#endif
