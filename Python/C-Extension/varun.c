#include <Python.h>
#include <stdlib.h>

static PyObject* varun_say_hello(PyObject *self)
{
	return Py_BuildValue("s", "Varun says hello. :)");
}

static PyObject* varun_system(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;
	
	if(!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	
	sts = system(command);
	return Py_BuildValue("i", sts);
	
}

static PyObject *varun_add(PyObject *self, PyObject *args)
{
	int a;
	int b;
	
	if(!PyArg_ParseTuple(args, "ii", &a, &b)
	{
		return NULL;
	}

	return Py_BuildValue("i", a + b);
	
}

static PyObject *varun_subtract(PyObject *self, PyObject *args)
{
	int a, b;
	
	if(!PyArg_ParseTuple(args, "ii", &a, &b))
	{
		return NULL;
	}
	
	return Py_BuildValue("i", a - b);
}


static PyMethodDef varun_methods[] = {
	{ "say_hello", (PyCFunction)varun_say_hello, METH_VARARGS, NULL },
	{ "system", (PyCFunction)varun_system, METH_VARARGS, NULL },
	{ "add", (PyCFunction)varun_add, METH_VARARGS, NULL },
	{ "subtract", (PyCFunction)varun_subtract, METH_VARARGS, NULL },
	{ NULL, NULL, 0, NULL }		
};


PyMODINIT_FUNC initvarun(void)
{
	(void) Py_InitModule("varun", varun_methods);
}



	
