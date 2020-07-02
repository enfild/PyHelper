/* Этот класс позволит вопроизводить питоновские скрипты
 *
 *edrt
 *egfdfg
 * eryery
 */
#ifndef PYHELPER_HPP
#define PYHELPER_HPP
#pragma once

#include <Python.h>

class CppPyInstance
{
public:
	CppPyInstance()
	{
		Py_Initialize();
	}

	~CppPyInstance()
	{
		Py_Finalize();
	}
};

class CppPyObject
{
private:
	PyObject *p;
public:
	CppPyObject() : p(nullptr)
	{}

	CppPyObject(PyObject* _p) : p(_p)
	{}

	~CppPyObject()
	{
		Release();
	}

	PyObject* getObject() const
	{
		return p;
	}

	PyObject* setObject(PyObject* _p)
	{
		return (p=_p);
	}

	PyObject* AddRef() const
	{
		if(p)
		{
			Py_INCREF(p);
		}
		return p;
	}

	void Release()
	{
		if(p)
		{
			Py_DECREF(p);
		}

		p= NULL;
	}

	PyObject* operator ->() const
	{
		return p;
	}

	bool is()
	{
		return p ? true : false;
	}

	operator PyObject*() const
	{
		return p;
	}

	PyObject* operator = (PyObject* pp)
	{
		p = pp;
		return p;
	}

	operator bool() const
	{
		return p ? true : false;
	}
};

#endif