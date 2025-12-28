/*
 * Codigo generado originalmente por rpcgen como plantilla de guía para uso en desarrollo 
 * 
 * El código fue enriquecido para hacer un "servidor" efectua una operación aritmética sobre dos números
 * conforme al caracter de operación.
 * 
 */

#include "IDL.h"
#include <stdio.h>

float *add_6_svc(values *argp, struct svc_req *rqstp)
{

	static float  result;

	result = argp->num1 + argp->num2;

	return &result;
}

float *sub_6_svc(values *argp, struct svc_req *rqstp)
{

	static float  result;

	result = argp->num1 - argp->num2;

	return &result;
}

float *mul_6_svc(values *argp, struct svc_req *rqstp)
{

	static float  result;

	result = argp->num1 * argp->num2;

	return &result;
}

float * div_6_svc(values *argp, struct svc_req *rqstp)
{
	static float  result;

	result = argp->num1 / argp->num2;

	return &result;
}
