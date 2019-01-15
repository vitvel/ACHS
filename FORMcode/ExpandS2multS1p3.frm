#-
#include harmpol.hh

L [S(R(2),N)] = + S(R(2),N) ;

multiply S(R(1),N)^3;

* Convert product to basis
#call basis(S)

* Inverse Mellin
#call invmel(S,N,H,x)

* Expand a general H-function into an expansion in x and ln(x)
#call hexpa(H,S)

B ln_;
print +s;
.end
