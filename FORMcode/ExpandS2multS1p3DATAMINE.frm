#-
#include harmpol.hh
s e3,e5,e7,e9,e11,e13;
s h31,h311,h31,h311,z11,h51,h3111,h511,h31111,h331,h71,h5111,h311111,h53,h3311,w;
s h711,h51111,h3111111,h531,h513,h33111,h31311,h91,h7111,h511111,h31111111,h73,h5311,h5131,h5113,h3331,h331111,h313111;
s h911,h71111,h5111111,h311111111,h731,h713,h551,h533,h33131,h33311,h51113,h51131,h51311,h53111,h3113111,h3131111,h3311111;
s hB1,h9111,h711111,h51111111,h3111111111,h75,h93,h5133,h5313,h5331,h5511,h7113,h7131,h7311,h331131,h331311,h333111,h511113,h511131,h511311,h513111,h531111,h31131111,h31311111,h33111111;


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
