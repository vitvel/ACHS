(* Add here path to ACtables if necessary *)

AppendTo[$Path, FileNameJoin[{$HomeDirectory,"Work/Paper/AC/ACHS"}]];

(* Load ACtables. ACtables1.m contains definition of the harmonic sums *)

ACT=Join[Get[StringJoin["ACtable/ACtable",ToString[#],".m"]]&/@Range[11]]//Flatten;

(* Dispatch tables to speed up the substitution *)

DACT=Dispatch[ACT];

(* Load the four-loop anomalous dimension in N=4 SYM *)

ADN3LO=Get["AD/ADN3LO.m"];

(* Load the six-loop anomalous dimension in N=4 SYM *)

ADN5LO=Get["AD/ADN5LO.m"];

(* Expand ADN3LO in the double-logarithmic point, i.e. N=-2+w up to interesting power of w *) 

ADN3LODL=ADN3LO/.S[i__]:>S[R[i],N]/.DACT/.S[R[a__],i]:>HS[a,1]/.signN->1/.signx->1//Series[#,{w,0,9}]&//Normal//Collect[#,{g,w}]&;

(* Make expansion as in eq.(47) *)

ADN2LODL=Normal[Series[Coefficient[ADN3LODL,g^2],{w,0,6}]]g^2+Normal[Series[Coefficient[ADN3LODL,g^4],{w,0,4}]]g^4+Normal[Series[Coefficient[ADN3LODL,g^6],{w,0,2}]]g^6;

(* Substitute in the double-logarithmic equation as in eq.(48) *)

ADN2LODL(2 w+ADN2LODL)//Series[#,{g,0,6}]&//Normal//Series[#,{w,0,0}]&//Normal//Expand//Collect[#/.{z2^2->Zeta[2]^2/Zeta[4] z4,z2^3->Zeta[2]^3/Zeta[6] z6,(z2 z4)->(Zeta[2]Zeta[4])/Zeta[6] z6},{g,w}]&

(* Expansion ADN4LO in the BFKL point, i.e. N=-1+w up to constant term *)

ADN3LOBFKL=ADN3LO/.S[i__]:>S[R[i],N]/.DACT/.signN->1/.signx->-1/.S[R[a__],i]:>HS[a,0]//Series[#,{w,0,0}]&//Normal//Collect[#/.{z2^2->Zeta[2]^2/Zeta[4] z4,z2^3->Zeta[2]^3/Zeta[6] z6,(z2 z4)->(Zeta[2]Zeta[4])/Zeta[6] z6},{g,w}]&

(* The function for the expansion of the harmonic sums near positive integer values as in the middle of the section 4 before eq.(44) *)

SPE[s_,j_]:=Flatten[{S[#][i_,k__]:>S[#-1][i,k]+Sign[i]^(#+s)/(#+w)^Abs[i]*S[#][k],S[#][i_]:>S[#-1][i]+Sign[i]^(#+s)/(#+w)^Abs[i]}&/@Range[0,j]];

(* The expansion of the four-loop anomalous dimension near N=0+w as in eq.(49) - compare with eqs. (D.1) and (D.4) form hep-th/1402.0871 *)

ADN3LO/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->(1)/.signx->1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,2}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&

ADN3LO/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->(1)/.signx->1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,3}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g},Expand]&

(* To speed up the computations for the five and six loops we apply expansion for each harmonic sums and the collect it together *)

Timing[ADN4LON0=Table[Coefficient[ADN5LO,g^10][[ii1]]/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->(1)/.signx->1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,3}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&,{ii1,1,Coefficient[ADN5LO,g^10]//Length}];]

Expand[Plus@@ADN4LON0]//Collect[#,w]&

(* Six loops demand a lot of time - don't run *)

(* Timing[ADN5LON0=Table[Coefficient[ADN5LO,g^12][[ii1]]/.S[i__]\[RuleDelayed]S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN\[Rule](1)/.signx\[Rule]1/.S[R[k__],i]\[RuleDelayed]HS[k,0]//Series[#,{w,0,1}]&//Normal//Collect[#/.{z2\[Rule]Zeta[2],z4\[Rule]Zeta[4],z6\[Rule]Zeta[6],z8\[Rule]Zeta[8],z10\[Rule]Zeta[10],z12\[Rule]Zeta[12]},{w,g}]&,{ii1,1,(Coefficient[ADN5LO,g^12]//Length)}];] *)

(* Expand[Plus@@ADN5LON0]//Collect[#,w]& *)

(* Expansion results for the BFKL eigenvalues *)

(* Load results for the BFKL eigenvalues *)

LLABFKL=Get["AD/LLABFKL.m"];
NLLABFKL=Get["AD/NLLABFKL.m"];
NNLLABFKL=Get["AD/NNLLABFKL.m"];

(* Expand as in eq.(50) *)

NNLLABFKLM1=NNLLABFKL/.S[i__]:>S[R[i],N]/.DACT/.signN->1/.signx->-1/.S[R[i3__],i]:>HS[i3,0]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
NNLLABFKLP0=NNLLABFKL/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
(NNLLABFKLM1/.w->-w/2)+(NNLLABFKLP0/.w->w/2)//Expand//Collect[#,w]&

(* Expand as in eq.(51) *)

NNLLABFKLM5=NNLLABFKL/.S[i__]:>S[R[i],N]/.DACT/.signN->1/.signx->-1/.S[R[i3__],i]:>HS[i3,2]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
NNLLABFKLP4=NNLLABFKL/.S[i__]:>S[2][i]//.SPE[0,2]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
(NNLLABFKLM5/.w->-w/2)+(NNLLABFKLP4/.w->w/2)//Expand//Collect[#,w]&

(* Expand as in eq.(52) *)

NNLLABFKLM3=NNLLABFKL/.S[i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[i3__],i]:>HS[i3,1]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
NNLLABFKLP2=NNLLABFKL/.S[i__]:>S[1][i]//.SPE[1,1]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->-1/.S[R[k__],i]:>HS[k,0]//Series[#,{w,0,4}]&//Normal//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8],z10->Zeta[10],z12->Zeta[12]},{w,g}]&
(NNLLABFKLM3/.w->-w/2)+(NNLLABFKLP2/.w->w/2)//Expand//Collect[#,w]&

(* Load the results for the BFKL intercept was derived for the arbitrary conformal spin *)

N3LLABFKLn=Get["AD/N3LLABFKLn.m"];

LLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,2}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6]},{w,g}]&

NLLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,2}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6]},{w,g}]&

NNLLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,2}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6]},{w,g}]&

NNNLLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,2}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8]},{w,g}]&

(* The expansion near 0+w compare with eq(5.44) and eq.(5.133) from hep-th/1802.06908 *)

N3LLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,2}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8]},{w,g}]&

(* The result for the high-order expansion in powers of w *)

N3LLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,3}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8]},{w,g}]&

N3LLABFKLn/.S[i__]:>S[0][i]//.SPE[0,0]/.S[-1][i__]:>S[R[i],N]/.DACT/.signN->1/.signx->1/.S[R[k__],i]:>HS[k,0]//Collect[#,w]&//Series[#,{w,0,4}]&//Normal//Expand[#/.w->w/2]&//Collect[#/.{z2->Zeta[2],z4->Zeta[4],z6->Zeta[6],z8->Zeta[8]},{w,g}]&
