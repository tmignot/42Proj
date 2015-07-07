%include "std_string.i"
%include "std_vector.i"
%include "std_map.i"

%template(IntVector) std::vector<int>;

%typemap(out) (bool) {
  $result = $1 == 1 ? Qtrue : Qfalse;
}
%typemap(out) (bool&) {
  $result = *$1 == 1 ? Qtrue : Qfalse;
}

%typemap(in) (bool) {
  $1 = $input == Qtrue ? 1 : 0;
}
