#ifndef FOO_DATA_H
#define FOO_DATA_H


#ifdef __cplusplus
namespace foo
{
#endif // __cplusplus


struct Data
{
  wchar_t* name;
  double*  valuesPtr;
  size_t   valuesLen;
};


#ifdef __cplusplus
} // namespace foo
#endif // __cplusplus


#endif // FOO_DATA_H
