%module test
%{
#include <map>
  extern VALUE Print(VALUE i);
  extern void  PrintMap(std::map<ID,unsigned int> m);
%}

%{
  void Yield(void* i) {
    VALUE rb_i = ULONG2NUM((unsigned long)i);
    rb_yield(rb_i);
  }
%}

%include <stl.i>
%include <std_string.i>
%typemap(in) (std::map<ID,unsigned int>)
  (VALUE keys_arr, int i, VALUE key, VALUE val) {
    Check_Type($input, T_HASH);
    keys_arr = rb_funcall($input, rb_intern("keys"), 0, NULL);
    i = NUM2INT(rb_funcall($input, rb_intern("size"), 0, NULL));
    for (i=i-1;i>=0;--i) {
      key = rb_ary_entry(keys_arr, i);
      val = rb_hash_aref($input, key);
      Check_Type(key, T_SYMBOL);
      Check_Type(val, T_FIXNUM);
      $1[SYM2ID(key)] = NUM2UINT(val);
    }
  }

extern VALUE Print(VALUE i);
extern void  PrintMap(std::map<ID,unsigned int> m);
