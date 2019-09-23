#include <jni.h>
#include <string>
#include "HashSodium.h"


//
// Created by nordo on 23/09/19.
//

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_lib_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

        /**new instance of our Object
        * the name of the class is Ext
        * hash.Hash() this method return the hash of the string "Souri ABDELHALIM"
        * the output of crypto_generichash function return non-ascii characters, so i converted that output to the hex using the
        * sodium_bin2hex fucntion
    */
    HashSodium hash;
    return env->NewStringUTF(hash.Hash().c_str());
}
