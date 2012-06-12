#include "util.h"
#include "java_lang_List_Util.h"

jint java_lang_List_size(JNIEnv* env, jobject jList) 
{
	// WARNING: donot cache these methods, list class may be different based on the object jlist
	jclass jListClass = env->GetObjectClass(jList);
	if (jListClass == NULL)
        return -1;
    jmethodID jListSizeMethodId = env->GetMethodID(jListClass, "size", "()I");
	if (jListSizeMethodId == NULL) {
        ThrowException(env, NoSuchMethod, "jList", "size");
		return -1;
	}
	return env->CallIntMethod(jList, jListSizeMethodId);
}

jobject java_lang_List_get(JNIEnv* env, jobject jList, jint index) 
{
	// WARNING: donot cache these methods/classes, list class may be different based on the object jlist
	jclass jListClass = env->GetObjectClass(jList);
	 if (jListClass == NULL)
        return NULL;
    jmethodID jListGetMethodId = env->GetMethodID(jListClass, "get", "(I)Ljava/lang/Object;");
	if (jListGetMethodId == NULL) {
		ThrowException(env, NoSuchMethod, "jList", "get");
        return NULL;
	}
    return env->CallObjectMethod(jList, jListGetMethodId, index);
}