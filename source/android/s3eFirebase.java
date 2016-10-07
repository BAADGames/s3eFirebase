/*
java implementation of the s3eFirebase extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

import com.google.firebase.analytics.FirebaseAnalytics;

class s3eFirebase
{
    private FirebaseAnalytics mFirebaseAnalytics;
    
    public void s3eFirebaseInitialize()
    {
        mFirebaseAnalytics = FirebaseAnalytics.getInstance(LoaderAPI.getActivity());
    }
}
