#-
#include harmpol.h

L [S(R(2),N)] = + S(R(2),N) ;

* Inverse Mellin
#call invmel(S,N,H,x)

* Expand a general H-function into an expansion in x and ln(x)
#call hexpa(H,S)

B ln_;
print +s;
.end
