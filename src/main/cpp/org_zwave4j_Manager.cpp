#include <Manager.h>
#include <Notification.h>
#include "../headers/init.h"
#include "../headers/org_zwave4j_Manager.h"

jobject getNotificationType(JNIEnv * env, OpenZWave::Notification::NotificationType type)
{
	const char * name;
	switch(type) 
	{
	case OpenZWave::Notification::Type_ValueAdded:
		name = "VALUE_ADDED";
		break;
	case OpenZWave::Notification::Type_ValueRemoved:
		name = "VALUE_REMOVED";
		break;
	case OpenZWave::Notification::Type_ValueChanged:
		name = "VALUE_CHANGED";
		break;
	case OpenZWave::Notification::Type_ValueRefreshed:
		name = "VALUE_REFRESHED";
		break;
	case OpenZWave::Notification::Type_Group:
		name = "GROUP";
		break;
	case OpenZWave::Notification::Type_NodeNew:
		name = "NODE_NEW";
		break;
	case OpenZWave::Notification::Type_NodeAdded:
		name = "NODE_ADDED";
		break;
	case OpenZWave::Notification::Type_NodeRemoved:
		name = "NODE_REMOVED";
		break;
	case OpenZWave::Notification::Type_NodeProtocolInfo:
		name = "NODE_PROTOCOL_INFO";
		break;
	case OpenZWave::Notification::Type_NodeNaming:
		name = "NODE_NAMING";
		break;
	case OpenZWave::Notification::Type_NodeEvent:
		name = "NODE_EVENT";
		break;
	case OpenZWave::Notification::Type_PollingDisabled:
		name = "POLLING_DISABLED";
		break;
	case OpenZWave::Notification::Type_PollingEnabled:
		name = "POLLING_ENABLED";
		break;
	case OpenZWave::Notification::Type_SceneEvent:
		name = "SCENE_EVENT";
		break;
	case OpenZWave::Notification::Type_CreateButton:
		name = "CREATE_BUTTON";
		break;
	case OpenZWave::Notification::Type_DeleteButton:
		name = "DELETE_BUTTON";
		break;
	case OpenZWave::Notification::Type_ButtonOn:
		name = "BUTTON_ON";
		break;
	case OpenZWave::Notification::Type_ButtonOff:
		name = "BUTTON_OFF";
		break;
	case OpenZWave::Notification::Type_DriverReady:
		name = "DRIVER_READY";
		break;
	case OpenZWave::Notification::Type_DriverFailed:
		name = "DRIVER_FAILED";
		break;
	case OpenZWave::Notification::Type_DriverReset:
		name = "DRIVER_RESET";
		break;
	case OpenZWave::Notification::Type_EssentialNodeQueriesComplete:
		name = "ESSENTIAL_NODE_QUERIES_COMPLETE";
		break;
	case OpenZWave::Notification::Type_NodeQueriesComplete:
		name = "NODE_QUERIES_COMPLETE";
		break;
	case OpenZWave::Notification::Type_AwakeNodesQueried:
		name = "AWAKE_NODES_QUERIED";
		break;
	case OpenZWave::Notification::Type_AllNodesQueriedSomeDead:
		name = "ALL_NODES_QUERIED_SOME_DEAD";
		break;
	case OpenZWave::Notification::Type_AllNodesQueried:
		name = "ALL_NODES_QUERIED";
		break;
	case OpenZWave::Notification::Type_Notification:
		name = "NOTIFICATION";
		break;
	}

	jclass clazz = findClass(env, "org/zwave4j/NotificationType");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/NotificationType;"));
}

jobject getValueType(JNIEnv * env, OpenZWave::ValueID::ValueType type)
{
	const char * name;
	switch(type)
	{
	case OpenZWave::ValueID::ValueType_Bool:
		name = "BOOL";
		break;
	case OpenZWave::ValueID::ValueType_Byte:
		name = "BYTE";
		break;
	case OpenZWave::ValueID::ValueType_Decimal:
		name = "DECIMAL";
		break;
	case OpenZWave::ValueID::ValueType_Int:
		name = "INT";
		break;
	case OpenZWave::ValueID::ValueType_List:
		name = "LIST";
		break;
	case OpenZWave::ValueID::ValueType_Schedule:
		name = "SCHEDULE";
		break;
	case OpenZWave::ValueID::ValueType_Short:
		name = "SHORT";
		break;
	case OpenZWave::ValueID::ValueType_String:
		name = "STRING";
		break;
	case OpenZWave::ValueID::ValueType_Button:
		name = "BUTTON";
		break;
	case OpenZWave::ValueID::ValueType_Raw:
		name = "RAW";
		break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ValueType");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ValueType;"));
}

jobject getValueGenre(JNIEnv * env, OpenZWave::ValueID::ValueGenre type)
{
	const char * name;
	switch(type)
	{
	case OpenZWave::ValueID::ValueGenre_Basic:
		name = "BASIC";
		break;
	case OpenZWave::ValueID::ValueGenre_User:
		name = "USER";
		break;
	case OpenZWave::ValueID::ValueGenre_Config:
		name = "CONFIG";
		break;
	case OpenZWave::ValueID::ValueGenre_System:
		name = "SYSTEM";
		break;
	case OpenZWave::ValueID::ValueGenre_Count:
		name = "COUNT";
		break;
	}
	jclass clazz = findClass(env, "org/zwave4j/ValueGenre");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, name, "Lorg/zwave4j/ValueGenre;"));
}

jobject getValueId(JNIEnv * env, OpenZWave::ValueID const * ozwValueId)
{
	jclass clazz = findClass(env, "org/zwave4j/ValueId");
	return env->NewObject(
		clazz,
		env->GetMethodID(clazz, "<init>", "(JSLorg/zwave4j/ValueGenre;SSSLorg/zwave4j/ValueType;J)V"),
		ozwValueId->GetHomeId(),
		ozwValueId->GetNodeId(),
		getValueGenre(env, ozwValueId->GetGenre()),
		ozwValueId->GetCommandClassId(),
		ozwValueId->GetInstance(),
		ozwValueId->GetIndex(),
		getValueType(env, ozwValueId->GetType()),
		ozwValueId->GetId()
	);
}

jobject getManager(JNIEnv * env)
{
	jclass clazz = findClass(env, "org/zwave4j/Manager");
	return env->GetStaticObjectField(clazz, env->GetStaticFieldID(clazz, "instance", "Lorg/zwave4j/Manager;"));
}

jobject getNotification(JNIEnv * env, OpenZWave::Notification const * ozwNotification)
{
	jclass clazz = findClass(env, "org/zwave4j/Notification");
	return env->NewObject(
		clazz,
		env->GetMethodID(clazz, "<init>", "(Lorg/zwave4j/NotificationType;Lorg/zwave4j/ValueId;S)V"),
		getNotificationType(env, ozwNotification->GetType()),
		getValueId(env, &ozwNotification->GetValueID()),
		ozwNotification->GetByte()
	);
}

OpenZWave::ValueID::ValueType getOzwValueType(JNIEnv * env, jobject valueType)
{
	jstring name = (jstring) env->CallObjectMethod(
		valueType, env->GetMethodID(findClass(env, "org/zwave4j/ValueType"), "name", "()Ljava/lang/String;")
	);
	const char * nameChars = env->GetStringUTFChars(name, NULL);
	OpenZWave::ValueID::ValueType ozwValueType;
	if (strcmp(nameChars, "BOOL") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Bool;
	else if (strcmp(nameChars, "BYTE") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Byte;
	else if (strcmp(nameChars, "DECIMAL") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Decimal;
	else if (strcmp(nameChars, "INT") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Int;
	else if (strcmp(nameChars, "LIST") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_List;
	else if (strcmp(nameChars, "SCHEDULE") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Schedule;
	else if (strcmp(nameChars, "SHORT") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Short;
	else if (strcmp(nameChars, "STRING") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_String;
	else if (strcmp(nameChars, "BUTTON") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Button;
	else if (strcmp(nameChars, "RAW") == 0)
		ozwValueType = OpenZWave::ValueID::ValueType_Raw;

	env->ReleaseStringUTFChars(name, nameChars);
	return ozwValueType;
}

OpenZWave::ValueID::ValueGenre getOzwValueGenre(JNIEnv * env, jobject valueGenre)
{
	jstring name = (jstring) env->CallObjectMethod(
		valueGenre, env->GetMethodID(findClass(env, "org/zwave4j/ValueGenre"), "name", "()Ljava/lang/String;")
	);
	const char * nameChars = env->GetStringUTFChars(name, NULL);
	OpenZWave::ValueID::ValueGenre ozwValueGenre;
	if (strcmp(nameChars, "BASIC") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Basic;
	else if (strcmp(nameChars, "USER") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_User;
	else if (strcmp(nameChars, "CONFIG") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Config;
	else if (strcmp(nameChars, "SYSTEM") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_System;
	else if (strcmp(nameChars, "COUNT") == 0)
		ozwValueGenre = OpenZWave::ValueID::ValueGenre_Count;

	env->ReleaseStringUTFChars(name, nameChars);
	return ozwValueGenre;
}

OpenZWave::ValueID getOzwValueId(JNIEnv * env, jobject valueId)
{
	jclass clazz = findClass(env, "org/zwave4j/ValueId");
	return OpenZWave::ValueID(
		(uint32) env->CallLongMethod(valueId, env->GetMethodID(clazz, "getHomeId", "()J")),
		(uint8) env->CallShortMethod(valueId, env->GetMethodID(clazz, "getNodeId", "()S")),
		getOzwValueGenre(
			env, env->CallObjectMethod(valueId, env->GetMethodID(clazz, "getGenre", "()Lorg/zwave4j/ValueGenre;"))
		),
		(uint8) env->CallShortMethod(valueId, env->GetMethodID(clazz, "getCommandClassId", "()S")),
		(uint8) env->CallShortMethod(valueId, env->GetMethodID(clazz, "getInstance", "()S")),
		(uint8) env->CallShortMethod(valueId, env->GetMethodID(clazz, "getIndex", "()S")),
		getOzwValueType(
			env, env->CallObjectMethod(valueId, env->GetMethodID(clazz, "getType", "()Lorg/zwave4j/ValueType;"))
		)
	);
}

void onNotification(OpenZWave::Notification const * ozwNotification, void * context)
{
	JNIEnv * env;
    int getEnvResult = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (getEnvResult == JNI_EDETACHED) {
        jvm->AttachCurrentThread((void **) &env, NULL);
    }

	env->CallVoidMethod(
		getManager(env),
		env->GetMethodID(findClass(env, "org/zwave4j/Manager"), "fireNotificationWatchers", "(Lorg/zwave4j/Notification;)V"),
		getNotification(env, ozwNotification)
	);

	jvm->DetachCurrentThread();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    createNativeManager
 * Signature: ()V;
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_createNativeManager
  (JNIEnv *, jclass)
{
	OpenZWave::Manager::Create();
	OpenZWave::Manager::Get()->AddWatcher(onNotification, NULL);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    destroyNativeManager
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_destroyNativeManager
  (JNIEnv *, jclass)
{
	OpenZWave::Manager::Get()->RemoveWatcher(onNotification, NULL);
	OpenZWave::Manager::Destroy();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    writeConfig
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_writeConfig
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->WriteConfig((uint32) homeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    addDriver
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_addDriver
  (JNIEnv * env, jobject object, jstring path)
{
	const char * pathChars = env->GetStringUTFChars(path, NULL);
	jboolean result = OpenZWave::Manager::Get()->AddDriver(std::string(pathChars)) ? JNI_TRUE : JNI_FALSE;
	env->ReleaseStringUTFChars(path, pathChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    removeDriver
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_removeDriver
  (JNIEnv * env, jobject object, jstring path)
{
	const char * pathChars = env->GetStringUTFChars(path, NULL);
	jboolean result = OpenZWave::Manager::Get()->RemoveDriver(std::string(pathChars)) ? JNI_TRUE : JNI_FALSE;
	env->ReleaseStringUTFChars(path, pathChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getPollInterval
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getPollInterval
  (JNIEnv * env, jobject object)
{
	return OpenZWave::Manager::Get()->GetPollInterval();
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setPollInterval
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setPollInterval
  (JNIEnv * env, jobject object, jint milliseconds, jboolean intervalBetweenPolls)
{
	OpenZWave::Manager::Get()->SetPollInterval(milliseconds, (intervalBetweenPolls == JNI_FALSE) ? false : true);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    enablePoll
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_enablePoll
  (JNIEnv * env, jobject object, jobject valueId, jshort intensity)
{
	return OpenZWave::Manager::Get()->EnablePoll(getOzwValueId(env, valueId), (uint8) intensity) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    disablePoll
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_disablePoll
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->DisablePoll(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isPolled
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isPolled
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->isPolled(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setPollIntensity
 * Signature: (Lorg/zwave4j/ValueId;S)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setPollIntensity
  (JNIEnv * env, jobject object, jobject valueId, jshort intensity)
{
	OpenZWave::Manager::Get()->SetPollIntensity(getOzwValueId(env, valueId), (uint8) intensity);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    refreshNodeInfo
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_refreshNodeInfo
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->RefreshNodeInfo((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestNodeState
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_requestNodeState
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->RequestNodeState((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestNodeDynamic
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_requestNodeDynamic
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->RequestNodeDynamic((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeListeningDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeListeningDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeListeningDevice((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeFrequentListeningDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeFrequentListeningDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeFrequentListeningDevice((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeBeamingDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeBeamingDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeBeamingDevice((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeRoutingDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeRoutingDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeRoutingDevice((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeSecurityDevice
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeSecurityDevice
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeSecurityDevice((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeMaxBaudRate
 * Signature: (JS)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getNodeMaxBaudRate
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeMaxBaudRate((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeVersion
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeVersion
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeVersion((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeSecurity
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeSecurity
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeSecurity((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeBasic
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeBasic
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeBasic((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeGeneric
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeGeneric
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeGeneric((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeSpecific
 * Signature: (JS)S
 */
JNIEXPORT jshort JNICALL Java_org_zwave4j_Manager_getNodeSpecific
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->GetNodeSpecific((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeType
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeType
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeType((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeNeighbors
 * Signature: (JSLjava/util/concurrent/atomic/AtomicReference;)J
 */
JNIEXPORT jlong JNICALL Java_org_zwave4j_Manager_getNodeNeighbors
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jobject nodeNeighbors)
{
	//TODO
	//return OpenZWave::Manager::Get()->GetNodeNeighbors((uint32) homeId, (uint8) nodeId, );
	return 0;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeManufacturerName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeManufacturerName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeManufacturerName((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductName((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeName
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeName((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeLocation
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeLocation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeLocation((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeManufacturerId
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeManufacturerId
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeManufacturerId((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductType
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductType
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductType((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeProductId
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeProductId
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeProductId((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeManufacturerName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeManufacturerName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring manufacturerName)
{
	const char * manufacturerNameChars = env->GetStringUTFChars(manufacturerName, NULL);
	OpenZWave::Manager::Get()->SetNodeManufacturerName((uint32) homeId, (uint8) nodeId, std::string(manufacturerNameChars));
	env->ReleaseStringUTFChars(manufacturerName, manufacturerNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeProductName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeProductName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring productName)
{
	const char * productNameChars = env->GetStringUTFChars(productName, NULL);
	OpenZWave::Manager::Get()->SetNodeProductName((uint32) homeId, (uint8) nodeId, std::string(productNameChars));
	env->ReleaseStringUTFChars(productName, productNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeName
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeName
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring nodeName)
{
	const char * nodeNameChars = env->GetStringUTFChars(nodeName, NULL);
	OpenZWave::Manager::Get()->SetNodeName((uint32) homeId, (uint8) nodeId, std::string(nodeNameChars));
	env->ReleaseStringUTFChars(nodeName, nodeNameChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeLocation
 * Signature: (JSLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeLocation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jstring location)
{
	const char * locationChars = env->GetStringUTFChars(location, NULL);
	OpenZWave::Manager::Get()->SetNodeLocation((uint32) homeId, (uint8) nodeId, std::string(locationChars));
	env->ReleaseStringUTFChars(location, locationChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeOn
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeOn
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->SetNodeOn((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeOff
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeOff
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->SetNodeOff((uint32) homeId, (uint8) nodeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setNodeLevel
 * Signature: (JSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setNodeLevel
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort level)
{
	OpenZWave::Manager::Get()->SetNodeLevel((uint32) homeId, (uint8) nodeId, (uint8) level);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeInfoReceived
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeInfoReceived
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeInfoReceived((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeClassInformation
 * Signature: (JSSLjava/lang/String;Ljava/lang/Short;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getNodeClassInformation
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort commandClassId, jstring className, jobject classVersion)
{
	const char * classNameChars;
	std::string classNameString;
	if (className != NULL) {
		classNameChars = env->GetStringUTFChars(className, NULL);
		classNameString = classNameChars;
	}
	uint8 ozwClassVersion;
	if (classVersion != NULL) {
		ozwClassVersion = (uint8) env->CallShortMethod(classVersion, env->GetMethodID(findClass(env, "java/lang/Short"), "shortValue", "()S"));
	}
	jboolean result = OpenZWave::Manager::Get()->GetNodeClassInformation(
	    (uint32) homeId,
	    (uint8) nodeId,
	    (uint8) commandClassId,
	    (className != NULL) ? &classNameString : NULL,
	    (classVersion != NULL) ? &ozwClassVersion : NULL
    ) ? JNI_TRUE : JNI_FALSE;

	if (className != NULL) {
		env->ReleaseStringUTFChars(className, classNameChars);
	}
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeAwake
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeAwake
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeAwake((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isNodeFailed
 * Signature: (JS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isNodeFailed
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return OpenZWave::Manager::Get()->IsNodeFailed((uint32) homeId, (uint8) nodeId) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getNodeQueryStage
 * Signature: (JS)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getNodeQueryStage
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetNodeQueryStage((uint32) homeId, (uint8) nodeId).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueLabel
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueLabel
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueLabel(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueLabel
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueLabel
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueLabel(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueUnits
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueUnits
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueUnits(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueUnits
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueUnits
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueUnits(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueHelp
 * Signature: (Lorg/zwave4j/ValueId;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_zwave4j_Manager_getValueHelp
  (JNIEnv * env, jobject object, jobject valueId)
{
	return env->NewStringUTF(OpenZWave::Manager::Get()->GetValueHelp(getOzwValueId(env, valueId)).c_str());
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueHelp
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setValueHelp
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL);
	OpenZWave::Manager::Get()->SetValueHelp(getOzwValueId(env, valueId), std::string(valueChars));
	env->ReleaseStringUTFChars(value, valueChars);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueMin
 * Signature: (Lorg/zwave4j/ValueId;)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getValueMin
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->GetValueMin(getOzwValueId(env, valueId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueMax
 * Signature: (Lorg/zwave4j/ValueId;)I
 */
JNIEXPORT jint JNICALL Java_org_zwave4j_Manager_getValueMax
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->GetValueMax(getOzwValueId(env, valueId));
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueReadOnly
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueReadOnly
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->IsValueReadOnly(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueWriteOnly
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueWriteOnly
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->IsValueWriteOnly(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValueSet
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValueSet
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->IsValueSet(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    isValuePolled
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_isValuePolled
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->IsValuePolled(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsBool
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsBool
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	bool ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsBool(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Boolean"),
			env->GetMethodID(findClass(env, "java/lang/Boolean"), "<init>", "(Z)V"),
			ozwValue ? JNI_TRUE : JNI_FALSE
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsByte
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsByte
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsByte(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Byte"),
			env->GetMethodID(findClass(env, "java/lang/Byte"), "<init>", "(B)V"),
			(jbyte) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsFloat
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsFloat
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	float ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsFloat(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Float"),
			env->GetMethodID(findClass(env, "java/lang/Float"), "<init>", "(F)V"),
			(jfloat) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsInt
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsInt
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int32 ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsInt(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			(jint) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsShort
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsShort
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int16 ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsShort(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			(jshort) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsString
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::string ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsString(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueAsRaw
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueAsRaw
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 * ozwValue;
	uint8 length;
	jboolean result = OpenZWave::Manager::Get()->GetValueAsRaw(getOzwValueId(env, valueId), &ozwValue, &length) ? JNI_TRUE : JNI_FALSE;
	//TODO
	/*env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		* ozwValue
	);*/
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListSelectionString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListSelectionString
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::string ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueListSelection(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewStringUTF(ozwValue.c_str())
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListSelectionInt
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListSelectionInt
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	int32 ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueListSelection(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Integer"),
			env->GetMethodID(findClass(env, "java/lang/Integer"), "<init>", "(I)V"),
			(jint) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueListItems
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/List;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueListItems
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	std::vector<std::string, std::allocator<std::string> > ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueListItems(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	//TODO
	/*env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		ozwValue
	);*/
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    getValueFloatPrecision
 * Signature: (Lorg/zwave4j/ValueId;Ljava/util/concurrent/atomic/AtomicReference;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_getValueFloatPrecision
  (JNIEnv * env, jobject object, jobject valueId, jobject value)
{
	uint8 ozwValue;
	jboolean result = OpenZWave::Manager::Get()->GetValueFloatPrecision(getOzwValueId(env, valueId), &ozwValue) ? JNI_TRUE : JNI_FALSE;
	env->CallVoidMethod(
		value,
		env->GetMethodID(findClass(env, "java/util/concurrent/atomic/AtomicReference"), "set", "(Ljava/lang/Object;)V"),
		env->NewObject(
			findClass(env, "java/lang/Short"),
			env->GetMethodID(findClass(env, "java/lang/Short"), "<init>", "(S)V"),
			(jshort) ozwValue
		)
	);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsBool
 * Signature: (Lorg/zwave4j/ValueId;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsBool
  (JNIEnv * env, jobject object, jobject valueId, jboolean value)
{
	return OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), value) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsByte
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsByte
  (JNIEnv * env, jobject object, jobject valueId, jshort value)
{
	return OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), value) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsFloat
 * Signature: (Lorg/zwave4j/ValueId;F)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsFloat
  (JNIEnv * env, jobject object, jobject valueId, jfloat value)
{
	return OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), value) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsInt
 * Signature: (Lorg/zwave4j/ValueId;I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsInt
  (JNIEnv * env, jobject object, jobject valueId, jint value)
{
	return OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), (int32) value) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsShort
 * Signature: (Lorg/zwave4j/ValueId;S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsShort
  (JNIEnv * env, jobject object, jobject valueId, jshort value)
{
	return OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), value) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsRaw
 * Signature: (Lorg/zwave4j/ValueId;[S)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsRaw
  (JNIEnv * env, jobject object, jobject valueId, jshortArray value)
{
	//TODO
	//env->GetShortArrayElements(value, NULL);
	//OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), );
	return JNI_TRUE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueAsString
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueAsString
  (JNIEnv * env, jobject object, jobject valueId, jstring value)
{
	const char * valueChars = env->GetStringUTFChars(value, NULL); 
	jboolean result = OpenZWave::Manager::Get()->SetValue(getOzwValueId(env, valueId), std::string(valueChars)) ? JNI_TRUE : JNI_FALSE;
	env->ReleaseStringUTFChars(value, valueChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setValueListSelection
 * Signature: (Lorg/zwave4j/ValueId;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setValueListSelection
  (JNIEnv * env, jobject object, jobject valueId, jstring selectedItem)
{
	const char * selectedItemChars = env->GetStringUTFChars(selectedItem, NULL); 
	jboolean result = OpenZWave::Manager::Get()->SetValueListSelection(getOzwValueId(env, valueId), std::string(selectedItemChars)) ? JNI_TRUE : JNI_FALSE;
	env->ReleaseStringUTFChars(selectedItem, selectedItemChars);
	return result;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    refreshValue
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_refreshValue
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->RefreshValue(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setChangeVerified
 * Signature: (Lorg/zwave4j/ValueId;Z)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_setChangeVerified
  (JNIEnv * env, jobject object, jobject valueId, jboolean verify)
{
	return OpenZWave::Manager::Get()->SetChangeVerified(getOzwValueId(env, valueId), (verify == JNI_FALSE) ? false : true);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    pressButton
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_pressButton
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->PressButton(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    releaseButton
 * Signature: (Lorg/zwave4j/ValueId;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_releaseButton
  (JNIEnv * env, jobject object, jobject valueId)
{
	return OpenZWave::Manager::Get()->ReleaseButton(getOzwValueId(env, valueId)) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    switchAllOn
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_switchAllOn
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->SwitchAllOn((uint32) homeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    switchAllOff
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_switchAllOff
  (JNIEnv * env, jobject object, jlong homeId)
{
	OpenZWave::Manager::Get()->SwitchAllOff((uint32) homeId);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    setConfigParam
 * Signature: (JSSIS)Z
 */
JNIEXPORT jboolean JNICALL Java_org_zwave4j_Manager_setConfigParam
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort param, jint value, jshort size)
{
	return OpenZWave::Manager::Get()->SetConfigParam((uint32) homeId, (uint8) nodeId, (uint8) param, value, (uint8) size) ? JNI_TRUE : JNI_FALSE;
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestConfigParam
 * Signature: (JSS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_requestConfigParam
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId, jshort param)
{
	OpenZWave::Manager::Get()->RequestConfigParam((uint32) homeId, (uint8) nodeId, (uint8) param);
}

/*
 * Class:     org_zwave4j_Manager
 * Method:    requestAllConfigParams
 * Signature: (JS)V
 */
JNIEXPORT void JNICALL Java_org_zwave4j_Manager_requestAllConfigParams
  (JNIEnv * env, jobject object, jlong homeId, jshort nodeId)
{
	OpenZWave::Manager::Get()->RequestAllConfigParams((uint32) homeId, (uint8) nodeId);
}