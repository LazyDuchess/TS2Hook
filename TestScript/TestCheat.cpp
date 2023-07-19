#include "pch.h"
#include "TestCheat.h"

const char* TestCheat::Name() {
	return "testCheat";
}

const char* TestCheat::Description(void* commandHelpType) {
	return "Does something crazy.";
}

void TestCheat::Execute(void* arguments) {
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			std::vector<TS::cTSObject*>* objects = objectMgr->GetObjects();
			std::wstring objMessage = L"Object Count: ";
			objMessage.append(std::to_wstring(objects->size()));
			MessageBox(NULL, objMessage.c_str(), L"Info!", MB_OK);
		}
	}
}

void SExecute(void* arguments) {
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			LinkedList<TS::cTSObject>* objects = objectMgr->GetObjectList();
			LinkedList<TS::cTSObject>::Node* node = objects->First();
			while (!node->IsHead())
			{
				TS::cTSObject* object = node->Pointer;
				MessageBox(NULL, Encoding::UTF8ToWString(object->GetName()).c_str(), L"Info!", MB_OK);
				node = node->Next;
			}
			//objectMgr->KillObject(434);
			/*
			int objectCount = objectMgr->GetObjectCount();
			std::wstring objMessage = L"LinkedList Object Count: ";
			objMessage.append(std::to_wstring(objects->Count()));
			objMessage.append(L"\n");
			objMessage.append(L"Actual Object Count: ");
			objMessage.append(std::to_wstring(objectCount));
			MessageBox(NULL, objMessage.c_str(), L"Info!", MB_OK);*/
			// around 641 in don's house?
			/*
			int objects = objectMgr->GetObjectCount();
			std::wstring objMessage = L"Object Amount: ";
			objMessage.append(std::to_wstring(objects));
			MessageBox(NULL, objMessage.c_str(), L"Info!", MB_OK);*/
			/*
			TS::cTSObject*** objects = objectMgr->GetObjects();
			std::wstring objMessage = L"First Object ID: ";
			objMessage.append(std::to_wstring(objects[0][0]->GetID()));
			MessageBox(NULL, objMessage.c_str(), L"Info!", MB_OK);*/
		}
	}
}

/*
* TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
			objectMgr->AdvanceSelectedPerson();
	}
*/

/*
	TS::cTSGameStateController* pGameStateController = TS::GameStateController();
	TS::cTSNeighborhoodInfo* nhInfo = pGameStateController->CurrentNeighborhoodInfo();
	std::wstring hoodType = L"Current Neighborhood Type: ";
	hoodType.append(std::to_wstring(nhInfo->NeighborhoodType()));
	MessageBox(NULL, hoodType.c_str(), L"Info!", MB_OK);*/