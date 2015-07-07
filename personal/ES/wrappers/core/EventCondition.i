%include "../include/core/EventCondition.hpp"

%typemap(in) (std::vector<NG::EventCondition*>) {
  Check_Type($input, T_ARRAY);
  int len = NUM2INT(rb_funcall($input, rb_intern("size"), 0, 0, NULL));
  std::vector<NG::EventCondition*> vec;
  vec.reserve(len);
  /* for each EventCondition */
  for (int i = 0; i < len; ++i) {
    NG::EventCondition* ec = new NG::EventCondition();
    VALUE val = rb_ary_entry($input, i);
    Check_Type(val, T_ARRAY);
    int len2 = NUM2INT(rb_funcall(val, rb_intern("size"), 0, 0, NULL));
    assert(len2 >= 2);
    ec->system = NUM2INT(rb_funcall(rb_ary_entry(val, 0), rb_intern("id"), 0));
    std::vector<unsigned int> param;
    /* for each attribute */
    ec->param.reserve(len2 - 1);
    for (int j = 2; j < len2; ++j) {
      VALUE v = rb_ary_entry(val, j);
      Check_Type(v, T_FIXNUM);
      ec->param.push_back(NUM2INT(v));
    }
    vec.push_back(ec);
  }
  $1 = vec;
}

%{
#include <ruby.h>
#include "core/EventCondition.hpp"
%}

