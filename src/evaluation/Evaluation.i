%define DOCSTR
"The `Evaluation` module is a collection of classes like PerformanceMeasures for the SHOGUN toolkit."
%enddef

%module(docstring=DOCSTR,directors="1") Evaluation
%{
#define SWIG_FILE_WITH_INIT
%}

%feature("autodoc","0");

#ifdef HAVE_DOXYGEN
%include "evaluation/Evaluation_doxygen.i"
#endif

#ifdef HAVE_PYTHON
%init %{
	  import_array();
%}

%include "lib/python_typemaps.i"
#endif

%include "lib/common.i"
%include "lib/ShogunException.i"
%include "lib/io.i"
%include "base/SGObject.i"

%include "evaluation/PerformanceMeasures.i"