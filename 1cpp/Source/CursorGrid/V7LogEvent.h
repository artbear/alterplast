// V7LogEvent.h: interface for the CV7LogEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_V7LOGEVENT_H__08A00BE0_2151_4690_AE09_24F947AED3E0__INCLUDED_)
#define AFX_V7LOGEVENT_H__08A00BE0_2151_4690_AE09_24F947AED3E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../BLCollection.h"

// ������ ������� 1�
#define LOG_DP_RUNMODE_CONFIG          0x01
#define LOG_DP_RUNMODE_DEBUG           0x02
#define LOG_DP_RUNMODE_MONITOR         0x04
#define LOG_DP_RUNMODE_ENTERPRISE      0x08
#define LOG_DP_RUNMODE_ALL             (LOG_DP_RUNMODE_CONFIG|LOG_DP_RUNMODE_DEBUG|LOG_DP_RUNMODE_MONITOR|LOG_DP_RUNMODE_ENTERPRISE)
// ��������� ������ � ������� �����������
#define LOG_DP_CATEGORY_SESSION        0x01
#define LOG_DP_CATEGORY_ADMIN          0x02
#define LOG_DP_CATEGORY_DATACHANGE     0x04
#define LOG_DP_CATEGORY_INFORMATION    0x08
#define LOG_DP_CATEGORY_WARNING        0x10
#define LOG_DP_CATEGORY_ERROR          0x20
#define LOG_DP_CATEGORY_ALL            (LOG_DP_CATEGORY_SESSION|LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_DATACHANGE|LOG_DP_CATEGORY_INFORMATION|LOG_DP_CATEGORY_WARNING|LOG_DP_CATEGORY_ERROR)
// ������ �������� � SetFilter
#define LOG_DP_FILTER_PARAM_NO         0
#define LOG_DP_FILTER_PARAM_STR        1
#define LOG_DP_FILTER_PARAM_OBJ        2
#define LOG_DP_FILTER_PARAM_VL         4
#define LOG_DP_FILTER_PARAM_STR_VL     (LOG_DP_FILTER_PARAM_STR|LOG_DP_FILTER_PARAM_VL)
#define LOG_DP_FILTER_PARAM_OBJ_VL     (LOG_DP_FILTER_PARAM_OBJ|LOG_DP_FILTER_PARAM_VL)
// ��� ������
#define LOG_DP_FILTER_CLEAR            0
#define LOG_DP_FILTER_DATE             1
#define LOG_DP_FILTER_TIME             2
#define LOG_DP_FILTER_USER             3
#define LOG_DP_FILTER_MODE             4
#define LOG_DP_FILTER_EVENTTYPE        5
#define LOG_DP_FILTER_EVENT            6
#define LOG_DP_FILTER_CATEGORY         7
#define LOG_DP_FILTER_COMMENT          8
#define LOG_DP_FILTER_OBJECT           9
#define LOG_DP_FILTER_PRESENT          10
#define LOG_DP_FILTER_OBJECTKIND       11
#define LOG_DP_FIELD_POSITION          12
#define LOG_DP_FILTER_USING_BUFFER     13


#define _ROW_FIELD_INDEX_(a) (a-LOG_DP_FILTER_DATE)

const static TCHAR* LOG_DP_1C_LogFields[][2]=
{
	{_T("Date"),            _T("����")                 },	// 0
	{_T("Time"),            _T("�����")                },	// 1
	{_T("User"),            _T("������������")         },	// 2
	{_T("Mode"),            _T("�����")                },	// 3
	{_T("EventType"),       _T("����������")           },	// 4
	{_T("Event"),           _T("�������")              },	// 5
	{_T("Category"),        _T("���������")            },	// 6
	{_T("Comment"),         _T("�����������")          },	// 7
	{_T("Object"),          _T("������")               },	// 8
	{_T("ObjectPresent"),   _T("��������������������") },	// 9
	{_T("ObjectKind"),      _T("����������")           },	// 10
	{_T("Position"),        _T("�������")              }	// 11
};


const static struct LOG_DP_1C_EventInfo
{
	USHORT ResourceID;
	BYTE Modes;
	BYTE Categories;
	BYTE FilterParameter;
	SHORT Parent;
	BYTE Index;
} LOG_DP_1C_Events[]=
{
	{0, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR_VL,    -LOG_DP_FILTER_USER,   1},
	{0, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR,    -LOG_DP_FILTER_MODE,   2},
	{0, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR_VL,    -LOG_DP_FILTER_EVENTTYPE,   138},
	{0, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR_VL,    -LOG_DP_FILTER_EVENT,   137},
	{0, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR,    -LOG_DP_FILTER_CATEGORY,   3},
	{0, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR,    -LOG_DP_FILTER_COMMENT,   139},
	{0, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_OBJ_VL,    -LOG_DP_FILTER_OBJECT,   141},
	{0, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR,    -LOG_DP_FILTER_PRESENT,   142},
	{0, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL, LOG_DP_FILTER_PARAM_STR_VL,    -LOG_DP_FILTER_OBJECTKIND,   140},
#define LOG_DP_FOR_BACKWARD_COMPATIBILITY     9
	{4882, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_SESSION, LOG_DP_FILTER_PARAM_NO,    0,   4},
	{4840, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_SESSION, LOG_DP_FILTER_PARAM_NO, 4882,   5},
	{4841, LOG_DP_RUNMODE_ALL, LOG_DP_CATEGORY_SESSION, LOG_DP_FILTER_PARAM_NO, 4882,   6},
	{4890, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE, LOG_DP_FILTER_PARAM_NO, 0, 7},
	{4835, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE, LOG_DP_FILTER_PARAM_NO, 4890, 8},
	{4836, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE, LOG_DP_FILTER_PARAM_NO, 4890, 9},
	{4886, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 0, 10},
	{4815, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 11},
	{4816, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 12},
	{4819, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 13},
	{4817, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 14},
	{4818, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 15},
	{4820, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 16},
	{4821, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 17},
	{4822, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4886, 18},
	{4883, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE|LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 0, 19},
	{4796, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4883, 20},
	{4797, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4883, 21},
	{4799, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 22},
	{4862, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 23},
	{4800, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4883, 24},
	{4801, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 25},
	{4802, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 26},
	{4803, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 27},
	{4804, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 28},
	{4806, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 29},
	{4956, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 30},
	{4805, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 31},
	{4809, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 32},
	{4810, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 33},
	{4811, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 34},
	{4808, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 35},
	{4807, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 36},
	{4798, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4883, 37},
	{4888, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 0, 38},
	{4823, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4888, 39},
	{4824, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4888, 40},
	{4825, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4888, 41},
	{4826, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4888, 42},
	{4827, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4888, 43},
	{4889, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE|LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 0, 44},
	{4828, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4889, 45},
	{4829, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 46},
	{4830, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 47},
	{4831, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 48},
	{4832, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 49},
	{4833, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 50},
	{4834, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4889, 51},
	{4884, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 0, 52},
	{4812, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4884, 53},
	{4831, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4884, 54},
	{4814, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4884, 55},
	{4885, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 0, 56},
	{4842, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4885, 57},
	{4843, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4885, 58},
	{4844, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4885, 59},
	{4845, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4885, 60},
	{4887, LOG_DP_RUNMODE_MONITOR|LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_DATACHANGE|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 61},
	{4837, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4887, 62},
	{4838, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4887, 63},
	{4839, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4887, 64},
	{4916, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4887, 65},
	{4917, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_DATACHANGE,   LOG_DP_FILTER_PARAM_NO, 4887, 66},
	{4877, LOG_DP_RUNMODE_MONITOR, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4887, 67},
	{4919, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4887, 68},
	{4920, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4887, 69},
	{4891, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_INFORMATION|LOG_DP_CATEGORY_WARNING|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 70},
	{4847, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4891, 71},
	{4846, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4891, 72},
	{4910, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4891, 73},
	{4848, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4891, 74},
	{4911, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4891, 75},
	{4912, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_INFORMATION,   LOG_DP_FILTER_PARAM_NO, 4891, 76},
	{4913, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_WARNING,   LOG_DP_FILTER_PARAM_NO, 4891, 77},
	{4914, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4891, 78},
	{4915, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4891, 79},
	{4892, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 80},
	{4867, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4892, 81},
	{4851, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 82},
	{4852, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 83},
	{4854, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 84},
	{4849, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4892, 85},
	{4850, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 86},
	{4856, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 87},
	{4857, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 88},
	{4858, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 89},
	{4855, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4892, 90},
	{4873, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 91},
	{4941, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 92},
	{4944, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 93},
	{4942, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 94},
	{4943, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4892, 95},
	{4946, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 96},
	{4947, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 97},
	{4949, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 98},
	{4948, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 99},
	{4950, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4892, 100},
	{4893, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 101},
	{4869, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4893, 102},
	{4875, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 103},
	{4868, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 104},
	{4870, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 105},
	{4853, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4893, 106},
	{4931, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 107},
	{4872, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 108},
	{4874, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4893, 109},
	{4871, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4893, 110},
	{4896, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 111},
	{4861, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4896, 112},
	{4866, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4896, 113},
	{4863, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4896, 114},
	{4937, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4896, 115},
	{4864, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4896, 116},
	{4865, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4896, 117},
	{4895, LOG_DP_RUNMODE_CONFIG, LOG_DP_RUNMODE_ALL,   LOG_DP_FILTER_PARAM_NO, 0, 118},
	{4860, LOG_DP_RUNMODE_CONFIG, LOG_DP_RUNMODE_ALL,   LOG_DP_FILTER_PARAM_NO, 4895, 121},
	{4930, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 0, 122},
	{4897, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN|LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 0, 123},
	{4899, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 124},
	{4900, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 125},
	{4901, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 126},
	{4902, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 127},
	{4903, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 128},
	{4904, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 129},
	{4906, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 130},
	{4907, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 131},
	{4908, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 132},
	{4909, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ERROR,   LOG_DP_FILTER_PARAM_NO, 4897, 133},
	{4923, LOG_DP_RUNMODE_CONFIG, LOG_DP_CATEGORY_ADMIN,   LOG_DP_FILTER_PARAM_NO, 4897, 134},
	{4894, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL,   LOG_DP_FILTER_PARAM_NO, 0, 135},
	{4859, LOG_DP_RUNMODE_ENTERPRISE, LOG_DP_CATEGORY_ALL,   LOG_DP_FILTER_PARAM_NO, 4894, 136} // UserMsg
};

#define LOG_DP_EVENTS_COUNT                 sizeof(LOG_DP_1C_Events)/sizeof(LOG_DP_1C_EventInfo)+2 // 2 - ����������� �������: ������ � ��������� ���������� ��������� �������
#define LOG_DP_EVENT_TYPE_USER              _T("User")
#define LOG_DP_EVENT_USER_MSG               _T("UserMsg")
#define LOG_DP_EVENT_USER_MSG_INDEX         LOG_DP_EVENTS_COUNT-3
#define LOG_DP_EVENT_TYPE_USER_INDEX_BC     2
#define LOG_DP_EVENT_USER_MSG_INDEX_BC      3


class CV7LogEvent : public CMyContextBase, public CCollectionItem
{
    DECLARE_DYNCREATE(CV7LogEvent);
public:
	CV7LogEvent();
	virtual ~CV7LogEvent();

	BOOL GetPropIndex(CValue& Value) const;
	BOOL GetPropEventID(CValue& Value) const;
	BOOL GetPropEventDescr(CValue& Value) const;
	BOOL GetPropIsSystem(CValue& Value) const;

	void SetIndex(int nIndex) { m_nIndex = nIndex; }
	int GetIndex() const { return m_nIndex; }
	bool IsSystemEventType() const;

	DECLARE_MY_CONTEXT();

private:

	int m_nIndex;
};


class CLogEventsCollection : public CCollection
{
public:
	CLogEventsCollection();
	~CLogEventsCollection();

    int GetSize() const;
    CV7LogEvent* Add(LPCSTR szName);
    CV7LogEvent* Insert(int nIndex, LPCSTR szName);
	CV7LogEvent* GetAt(int nIndex) const;
    CV7LogEvent* GetAt(LPCSTR szName) const;
    int IndexOf(LPCSTR szName) const;
    int IndexOf(CV7LogEvent* pLogEvent) const;
    BOOL Remove(int nIndex);
    BOOL Move(int nIndex, int nOffset);
    void RemoveAll();
protected:
    virtual void OnRemove(CCollectionItem* pItem, int nIndexWas);
};


class CV7LogEventsCollection : public CBLCollection<CLogEventsCollection, CV7LogEvent, RUNTIME_CLASS(CV7LogEvent), BLC_READONLY>
{
	DECLARE_DYNAMIC(CV7LogEventsCollection);
public:
	virtual LPCSTR GetTypeString(void) const
	{
		if (GetMetaData()->GetTaskDef()->GetDefaultLanguage() == 0)
			return _T("LogEvents");
		else
			return _T("�������������������������");
	}
};


class CV7LogEventType : public CMyContextBase, public CCollectionItem
{
    DECLARE_DYNCREATE(CV7LogEventType);
public:
	CV7LogEventType();
	virtual ~CV7LogEventType();

	BOOL GetPropIndex(CValue& Value) const;
	BOOL GetPropEventID(CValue& Value) const;
	BOOL GetPropEventDescr(CValue& Value) const;
	BOOL GetPropEvents(CValue& Value) const;
	BOOL GetPropIsSystem(CValue& Value) const;

	void SetIndex(int nIndex);
	int GetIndex() const { return m_nIndex; }

	bool IsSystemEventType() const;
	void RemoveUserMessages();
	void AddUserEvent(LPCSTR szName, const int& nIndex);

	CV7LogEvent* FindEvent(LPCSTR szName) const;

	DECLARE_MY_CONTEXT();

private:

	int m_nIndex;

	CBLPtr<CV7LogEventsCollection> m_pEvents;
};


class CLogEventTypesCollection : public CCollection
{
public:
	CLogEventTypesCollection();
	~CLogEventTypesCollection();

    int GetSize() const;
    CV7LogEventType* Add(LPCSTR szName);
    CV7LogEventType* Insert(int nIndex, LPCSTR szName);
	CV7LogEventType* GetAt(int nIndex) const;
    CV7LogEventType* GetAt(LPCSTR szName) const;
    int IndexOf(LPCSTR szName) const;
    int IndexOf(CV7LogEventType* pLogEventType) const;
    BOOL Remove(int nIndex);
    BOOL Move(int nIndex, int nOffset);
    void RemoveAll();
protected:
    virtual void OnRemove(CCollectionItem* pItem, int nIndexWas);
};


class CV7LogEventTypesCollection : public CBLCollection<CLogEventTypesCollection, CV7LogEventType, RUNTIME_CLASS(CV7LogEventType), BLC_READONLY>
{
	DECLARE_DYNAMIC(CV7LogEventTypesCollection);
public:
	CV7LogEventTypesCollection();

	virtual LPCSTR GetTypeString(void) const
	{
		if (GetMetaData()->GetTaskDef()->GetDefaultLanguage() == 0)
			return _T("LogEventTypes");
		else
			return _T("�����������������������������");
	}
	void AddUserEvents(CString csEventsSource);
private:
	int m_nSystemEventsCount;
};

enum LOG_DP_EventResourcePart {erpIdentifier=1, erpDescription=2, erpCompletely=3};


BOOL GetResourceString(CString& csResource, const int& nResourceID, const LOG_DP_EventResourcePart erpPart);

#endif // !defined(AFX_V7LOGEVENT_H__08A00BE0_2151_4690_AE09_24F947AED3E0__INCLUDED_)