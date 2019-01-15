#-
#include harmpol.hh
s e3,e5,e7,e9,e11,e13;
s h31,h311,h31,h311,z11,h51,h3111,h511,h31111,h331,h71,h5111,h311111,h53,h3311,w;
s h711,h51111,h3111111,h531,h513,h33111,h31311,h91,h7111,h511111,h31111111,h73,h5311,h5131,h5113,h3331,h331111,h313111;
s h911,h71111,h5111111,h311111111,h731,h713,h551,h533,h33131,h33311,h51113,h51131,h51311,h53111,h3113111,h3131111,h3311111;
s hB1,h9111,h711111,h51111111,h3111111111,h75,h93,h5133,h5313,h5331,h5511,h7113,h7131,h7311,h331131,h331311,h333111,h511113,h511131,h511311,h513111,h531111,h31131111,h31311111,h33111111;
s Pi,signN,signx;

* define the weight of the multiplied harmonic sum, then used in the reexpansion of the obtained result

#define multS "10"

L [S(R(2),N)] = + S(R(2),N) ;

multiply S(R(`multS'),N);

* Convert product to basis
#call basis(S)

* Inverse Mellin
#call invmel(S,N,H,x)

* Expand a general H-function into an expansion in x and ln(x)
#call hexpa(H,S)

B ln_;
print +s;
.sort

* translate x-expansion into the expansion over w

id pow(x,i)*S(R,i)*[1-x]*[1+x]^-1*sum(i,1,inf) = - pow(-x,i);
id S(R,i)=1;
id pow(x,i)*S(R(i8?,?a),i)*[1-x]*[1+x]^-1*sum(i,1,inf) = pow(-x,i)*S(R(-i8,?a),i);
id pow(x,i)*sum(i,1,inf)=1;
id ln_(i8?,x)=(-1)^i8*fac_(i8)/w^i8/w;
id pow(-x,i)=signx;
id sign_(N)=signN;

* reexpand result subdividing into the same harmonic sum, in which the original expression was multiplied above

#include mult/multiplySi`multS'.prc

* rewrite some zeta-numbers in a usual way

id e3 =(1-1/4)*z3;
id e5 =(1-1/4/4)*z5;
id e7 =(1-1/4/4/4)*z7;
id e9 =(1-1/4/4/4/4)*z9;
id e11=(1-1/4/4/4/4/4)*z11;
id z2=Pi^2/6;
id z4=Pi^4/90;
id z6=Pi^6/945;
id z8=Pi^8/9450;
id z10=Pi^10/93555;
id z12=691*Pi^12/638512875;
id Pi^12=638512875*z12/691;
id Pi^10=93555*z10;
id Pi^8=9450*z8;
id Pi^6=945*z6;
id Pi^4=90*z4;
id Pi^2=6*z2;

* remove all unrelevant powers of the expnsion in w

#do i8={`multS'-1},100
id w^`i8'=0;
#enddo
.sort

B w;
print +s;
.end
