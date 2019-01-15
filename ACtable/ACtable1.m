(* Definition of the harmonic sums according eq.(1.2) from the paper *)

HS[a_/;(a!=0), jList__, n_?IntegerQ] := Sum[(Sign[a]^i/i^Abs[a])*HS[jList, i], {i, 1, n}]; 
HS[a_/;(a!=0), n_?IntegerQ] := Sum[Sign[a]^i/i^Abs[a], {i, 1, n}]; 

{
S[R[1],N]->-w^-1+z12*w^11-z11*w^10+z10*w^9-z9*w^8+z8*w^7-z7*w^6+z6*w^5-z5*w^4+z4*w^3-z3*w^2+z2*w+S[R[1],i]+S[R[2],i]*w+S[R[3],i]*w^2+S[R[4],i]*w^3+S[R[5],i]*w^4+S[R[6],i]*w^5+S[R[7],i]*w^6+S[R[8],i]*w^7+S[R[9],i]*w^8+S[R[10],i]*w^9+S[R[11],i]*w^10+S[R[12],i]*w^11,
S[R[-1],N]->-ln2-signx*w^-1*signN+signx*ln2*signN-2047/2048*signx*z12*w^11*signN+1023/1024*signx*z11*w^10*signN-511/512*signx*z10*w^9*signN+255/256*signx*z9*w^8*signN-127/128*signx*z8*w^7*signN+63/64*signx*z7*w^6*signN-31/32*signx*z6*w^5*signN+15/16*signx*z5*w^4*signN-7/8*signx*z4*w^3*signN+3/4*signx*z3*w^2*signN-1/2*signx*z2*w*signN+signx*S[R[-12],i]*w^11*signN+signx*S[R[-11],i]*w^10*signN+signx*S[R[-10],i]*w^9*signN+signx*S[R[-9],i]*w^8*signN+signx*S[R[-8],i]*w^7*signN+signx*S[R[-7],i]*w^6*signN+signx*S[R[-6],i]*w^5*signN+signx*S[R[-5],i]*w^4*signN+signx*S[R[-4],i]*w^3*signN+signx*S[R[-3],i]*w^2*signN+signx*S[R[-2],i]*w*signN+signx*S[R[-1],i]*signN
}
