#include "stdafx.h"
#include "IDmanager.h"

const int IDmanager::getObject(const Objects& obj) const {
	return static_cast<int>(obj);
}

Entity* IDmanager::createEntity(int id, int parameter) {
	switch (id) {
		
	}
	return nullptr; // temp
}

WorldObj* IDmanager::createWorldobj(int id, int parameter) {
	switch (id) {

	}
	return nullptr;
}
