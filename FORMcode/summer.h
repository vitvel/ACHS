#ifndef `SUMMER6HFILE'
#define  SUMMER6HFILE "1"
*--#[ nndecl.h :
#ifndef `NNDECLHFILE'
#define  NNDECLHFILE  "1"
*
*	Include file for declarations for harmonic summation program SUMMER
*
*	Parameters:
*	MAXWEIGHT: the maximum number of nested sums/ maximum weight
*	           sometimes the maximum number of indices of the R in S(R(),n)
*              sometimes the maximum value of the absolute value of the indices
*	File by J. Vermaseren
*
#define MAXWEIGHT "12"
*
*	First some automatic declarations. This way we do not have to worry how
*	many j1, j2, etc and S1, S2 etc. have been declared.
*	When a ifac8 or something like it will be encountered it will be
*	automatically declared as a CommutingFunction if it did not exist yet.
*
AutoDeclare Symbols i,j,k,l,m,n,x,y;
AutoDeclare CF sum,sign,bino,fac,ifac,invfac,num,den,S,H,X,Y,Z
			,theta,delta,Gamma,InvGamma;
*
*	Now the fixed declarations.
*
S	k,n,N,a,ep,[1-x],[1+x],[1-xxx],[1+xxx],one,[1-one],[1+one],Mel;
CF	f,f1,f2,f3,f4,R,RR,T,TT,su,A,div,addarg,ln,SSZZ;
CF	Conj,Conjp,rep,pow,ipow,epow,acc,acc1,G,GG,InvG,Num,Den,Even,Odd;
S	z1,...,z`MAXWEIGHT',ln2;
S	li4half,li5half,li6half,li7half,li8half,li9half,li10half;
S	s6,s7a,s7b,s8a,s8b,s8c,s8d,s9a,s9b,s9c,s9d,s9e,s9f;
S	s10a,s10b,s10c,s10d,s10e,s10f,s10g,s10h,s10i,s10j,s10k,s10l;
*
*	Some sets are needed for generating the sums in the mellin programs
*	(and other programs as well)
*
Set ii:i1,...,i`MAXWEIGHT';
Set jset:j1,...,j`MAXWEIGHT';
Set sumset:sum1,...,sum`MAXWEIGHT';
Set j2mset:j2m1,...,j2m`MAXWEIGHT';
Set sum2mset:sum2m1,...,sum2m`MAXWEIGHT';
Set denset:den1,...,den`MAXWEIGHT';
Set Sset:S1,...,S`MAXWEIGHT';
Set signset:sign1,...,sign`MAXWEIGHT';
Set zz:z1,...,z`MAXWEIGHT';
Set pos1:x1x1x,2,...,{2*`MAXWEIGHT'};
*
*	The powsum tables are to be used in more complete versions of the
*	summation program summit.prc
*	The program that derives these tables is below in this file
*	(in the fold programs, and then in the subfold sumprog)
*
*	Sum table: powsum(k,n) = sum_(j,1,n,j^k)
*
CTable powsum(0:20,n?);
Fill powsum(0) = n;
Fill powsum(1) = n*(n+1)/2;
Fill powsum(2) = n*(n+1)*(2*n+1)/6;
Fill powsum(3) = n^2*(n+1)^2/4;
Fill powsum(4) = n*(n+1)*(2*n+1)*(3*n^2+3*n-1)/30;
Fill powsum(5) =-1/12*n^2+5/12*n^4+1/2*n^5+1/6*n^6;
Fill powsum(6) =1/42*n-1/6*n^3+1/2*n^5+1/2*n^6+1/7*n^7;
Fill powsum(7) =1/12*n^2-7/24*n^4+7/12*n^6+1/2*n^7+1/8*n^8;
Fill powsum(8) =-1/30*n+2/9*n^3-7/15*n^5+2/3*n^7+1/2*n^8+1/9*n^9;
Fill powsum(9) =-3/20*n^2+1/2*n^4-7/10*n^6+3/4*n^8+1/2*n^9+1/10*n^10;
Fill powsum(10)=5/66*n-1/2*n^3+n^5-n^7+5/6*n^9+1/2*n^10+1/11*n^11;
Fill powsum(11)=
      5/12*n^2-11/8*n^4+11/6*n^6-11/8*n^8+11/12*n^10+1/2*n^11+1/12*n^12
      ;
Fill powsum(12)=
      -691/2730*n+5/3*n^3-33/10*n^5+22/7*n^7-11/6*n^9+n^11+1/2*n^12+1/
      13*n^13;
Fill powsum(13)=
      -691/420*n^2+65/12*n^4-143/20*n^6+143/28*n^8-143/60*n^10+13/12*
      n^12+1/2*n^13+1/14*n^14;
Fill powsum(14)=
      7/6*n-691/90*n^3+91/6*n^5-143/10*n^7+143/18*n^9-91/30*n^11+7/6*
      n^13+1/2*n^14+1/15*n^15;
Fill powsum(15)=
      35/4*n^2-691/24*n^4+455/12*n^6-429/16*n^8+143/12*n^10-91/24*n^12+
      5/4*n^14+1/2*n^15+1/16*n^16;
Fill powsum(16)=
      -3617/510*n+140/3*n^3-1382/15*n^5+260/3*n^7-143/3*n^9+52/3*n^11-
      14/3*n^13+4/3*n^15+1/2*n^16+1/17*n^17;
Fill powsum(17)=
      -3617/60*n^2+595/3*n^4-11747/45*n^6+1105/6*n^8-2431/30*n^10+221/9
      *n^12-17/3*n^14+17/12*n^16+1/2*n^17+1/18*n^18;
Fill powsum(18)=
      43867/798*n-3617/10*n^3+714*n^5-23494/35*n^7+1105/3*n^9-663/5*
      n^11+34*n^13-34/5*n^15+3/2*n^17+1/2*n^18+1/19*n^19;
Fill powsum(19)=
      43867/84*n^2-68723/40*n^4+2261*n^6-223193/140*n^8+4199/6*n^10-
      4199/20*n^12+323/7*n^14-323/40*n^16+19/12*n^18+1/2*n^19+1/20*n^20
      ;
Fill powsum(20)=
      -174611/330*n+219335/63*n^3-68723/10*n^5+6460*n^7-223193/63*n^9+
      41990/33*n^11-323*n^13+1292/21*n^15-19/2*n^17+5/3*n^19+1/2*n^20+1/
      21*n^21;
*
*	Sum table: mpowsum(k,n) = sum_(j,1,n,(-1)^j*j^k)
*
CTable mpowsum(0:20,n?);
Fill mpowsum(0) = (sign_(n)-1)/2;
Fill mpowsum(1) = ((2*n+1)*sign_(n)-1)/4;
Fill mpowsum(2) = n*(n+1)*sign_(n)/2;
Fill mpowsum(3) = ((4*n^3+6*n^2-1)*sign_(n)+1)/8;
Fill mpowsum(4) = n*(n+1)*(n^2+n-1)*sign_(n)/2;
Fill mpowsum(5) = ((2*n^5+5*n^4-5*n^2+1)*sign_(n)-1)/4;
Fill mpowsum(6) = n*(n+1)*(n^4+2*n^3-2*n^2-3*n+3)*sign_(n)/2;
Fill mpowsum(7) = ((8*n^7+28*n^6-70*n^4+84*n^2-17)*sign_(n)+17)/16;
Fill mpowsum(8) = n*(n+1)*(n^6+3*n^5-3*n^4-11*n^3+11*n^2+17*n-17)*sign_(n)/2;
Fill mpowsum(9) = ((2*n^9+9*n^8-42*n^6+126*n^4-153*n^2+31)*sign_(n)-31)/4;
Fill mpowsum(10)= n*(n+1)*(n^8+4*n^7-4*n^6-26*n^5+26*n^4+100*n^3-100*n^2-155*n+155)*sign_(n)/2;
Fill mpowsum(11)=
      +sign_(n)*(-691/8+1705/4*n^2-2805/8*n^4+231/2*n^6-165/8*n^8+11/4*
         n^10+1/2*n^11)
      +691/8;
Fill mpowsum(12)=
      +sign_(n)*(-2073/2*n+1705*n^3-1683/2*n^5+198*n^7-55/2*n^9+3*n^11+
         1/2*n^12);
Fill mpowsum(13)=
      +sign_(n)*(5461/4-26949/4*n^2+22165/4*n^4-7293/4*n^6+1287/4*n^8-
         143/4*n^10+13/4*n^12+1/2*n^13)
      -5461/4;
Fill mpowsum(14)=
      +sign_(n)*(38227/2*n-62881/2*n^3+31031/2*n^5-7293/2*n^7+1001/2*
         n^9-91/2*n^11+7/2*n^13+1/2*n^14);
Fill mpowsum(15)=
      +sign_(n)*(-929569/32+573405/4*n^2-943215/8*n^4+155155/4*n^6-
         109395/16*n^8+3003/4*n^10-455/8*n^12+15/4*n^14+1/2*n^15)
      +929569/32;
Fill mpowsum(16)=
      +sign_(n)*(-929569/2*n+764540*n^3-377286*n^5+88660*n^7-12155*n^9+
         1092*n^11-70*n^13+4*n^15+1/2*n^16);
Fill mpowsum(17)=
      +sign_(n)*(3202291/4-15802673/4*n^2+3249295*n^4-1068977*n^6+
         376805/2*n^8-41327/2*n^10+1547*n^12-85*n^14+17/4*n^16+1/2*n^17
         )
      -3202291/4;
Fill mpowsum(18)=
      +sign_(n)*(28820619/2*n-47408019/2*n^3+11697462*n^5-2748798*n^7+
         376805*n^9-33813*n^11+2142*n^13-102*n^15+9/2*n^17+1/2*n^18);
Fill mpowsum(19)=
      +sign_(n)*(-221930581/8+547591761/4*n^2-900752361/8*n^4+37041963*
         n^6-26113581/4*n^8+1431859/2*n^10-214149/4*n^12+2907*n^14-969/
         8*n^16+19/4*n^18+1/2*n^19)
      +221930581/8;
Fill mpowsum(20)=
      +sign_(n)*(-1109652905/2*n+912652935*n^3-900752361/2*n^5+
         105834180*n^7-14507545*n^9+1301690*n^11-82365*n^13+3876*n^15-
         285/2*n^17+5*n^19+1/2*n^20);
*
*	The next two tables are for speed purposes only.
*
*	powsum1(k,n) = sum_(j,1,n-1,j^k)
*
CTable powsum1(0:20,n?);
Fill powsum1(0) = -1+n;
Fill powsum1(1) = -1/2*n+1/2*n^2;
Fill powsum1(2) = 1/6*n-1/2*n^2+1/3*n^3;
Fill powsum1(3) = 1/4*n^2-1/2*n^3+1/4*n^4;
Fill powsum1(4) = -1/30*n+1/3*n^3-1/2*n^4+1/5*n^5;
Fill powsum1(5) =-1/12*n^2+5/12*n^4-1/2*n^5+1/6*n^6;
Fill powsum1(6) =1/42*n-1/6*n^3+1/2*n^5-1/2*n^6+1/7*n^7;
Fill powsum1(7) =1/12*n^2-7/24*n^4+7/12*n^6-1/2*n^7+1/8*n^8;
Fill powsum1(8) =-1/30*n+2/9*n^3-7/15*n^5+2/3*n^7-1/2*n^8+1/9*n^9;
Fill powsum1(9) =-3/20*n^2+1/2*n^4-7/10*n^6+3/4*n^8-1/2*n^9+1/10*n^10;
Fill powsum1(10)=5/66*n-1/2*n^3+n^5-n^7+5/6*n^9-1/2*n^10+1/11*n^11;
Fill powsum1(11)=
      +5/12*n^2-11/8*n^4+11/6*n^6-11/8*n^8+11/12*n^10-1/2*n^11+1/12*
         n^12;
Fill powsum1(12)=
      -691/2730*n+5/3*n^3-33/10*n^5+22/7*n^7-11/6*n^9+n^11-1/2*n^12+1/
         13*n^13;
Fill powsum1(13)=
      -691/420*n^2+65/12*n^4-143/20*n^6+143/28*n^8-143/60*n^10+13/12*
         n^12-1/2*n^13+1/14*n^14;
Fill powsum1(14)=
      +7/6*n-691/90*n^3+91/6*n^5-143/10*n^7+143/18*n^9-91/30*n^11+7/6*
         n^13-1/2*n^14+1/15*n^15;
Fill powsum1(15)=
      +35/4*n^2-691/24*n^4+455/12*n^6-429/16*n^8+143/12*n^10-91/24*n^12
         +5/4*n^14-1/2*n^15+1/16*n^16;
Fill powsum1(16)=
      -3617/510*n+140/3*n^3-1382/15*n^5+260/3*n^7-143/3*n^9+52/3*n^11-
         14/3*n^13+4/3*n^15-1/2*n^16+1/17*n^17;
Fill powsum1(17)=
      -3617/60*n^2+595/3*n^4-11747/45*n^6+1105/6*n^8-2431/30*n^10+221/9
         *n^12-17/3*n^14+17/12*n^16-1/2*n^17+1/18*n^18;
Fill powsum1(18)=
      +43867/798*n-3617/10*n^3+714*n^5-23494/35*n^7+1105/3*n^9-663/5*
         n^11+34*n^13-34/5*n^15+3/2*n^17-1/2*n^18+1/19*n^19;
Fill powsum1(19)=
      +43867/84*n^2-68723/40*n^4+2261*n^6-223193/140*n^8+4199/6*n^10-
         4199/20*n^12+323/7*n^14-323/40*n^16+19/12*n^18-1/2*n^19+1/20*
         n^20;
Fill powsum1(20)=
      -174611/330*n+219335/63*n^3-68723/10*n^5+6460*n^7-223193/63*n^9+
         41990/33*n^11-323*n^13+1292/21*n^15-19/2*n^17+5/3*n^19-1/2*
         n^20+1/21*n^21;
*
*	mpowsum1(k,n) = sum_(j,1,n-1,(-1)^j*j^k)
*
CTable mpowsum1(0:20,n?);
Fill mpowsum1(0) = -1/2-1/2*sign_(n);
Fill mpowsum1(1) = -1/4+1/4*sign_(n)-1/2*sign_(n)*n;
Fill mpowsum1(2) = 1/2*sign_(n)*n-1/2*sign_(n)*n^2;
Fill mpowsum1(3) = 1/8-1/8*sign_(n)+3/4*sign_(n)*n^2-1/2*sign_(n)*n^3;
Fill mpowsum1(4) = -1/2*sign_(n)*n+sign_(n)*n^3-1/2*sign_(n)*n^4;
Fill mpowsum1(5) = -1/4+1/4*sign_(n)-5/4*sign_(n)*n^2+5/4*sign_(n)*n^4
                  -1/2*sign_(n)*n^5;
Fill mpowsum1(6) = 3/2*sign_(n)*n-5/2*sign_(n)*n^3+3/2*sign_(n)*n^5
                  -1/2*sign_(n)*n^6;
Fill mpowsum1(7) = 17/16-17/16*sign_(n)+21/4*sign_(n)*n^2-35/8*sign_(n)*n^4
                  +7/4*sign_(n)*n^6-1/2*sign_(n)*n^7;
Fill mpowsum1(8) = -17/2*sign_(n)*n+14*sign_(n)*n^3-7*sign_(n)*n^5
                  +2*sign_(n)*n^7-1/2*sign_(n)*n^8;
Fill mpowsum1(9) = -31/4+31/4*sign_(n)-153/4*sign_(n)*n^2+63/2*sign_(n)*n^4
                  -21/2*sign_(n)*n^6+9/4*sign_(n)*n^8-1/2*sign_(n)*n^9;
Fill mpowsum1(10) = 155/2*sign_(n)*n-255/2*sign_(n)*n^3+63*sign_(n)*n^5
                  -15*sign_(n)*n^7+5/2*sign_(n)*n^9-1/2*sign_(n)*n^10;
Fill mpowsum1(11)=
      +sign_(n)*(-691/8+1705/4*n^2-2805/8*n^4+231/2*n^6-165/8*n^8+11/4*
         n^10-1/2*n^11)
      +691/8;
Fill mpowsum1(12)=
      +sign_(n)*(-2073/2*n+1705*n^3-1683/2*n^5+198*n^7-55/2*n^9+3*n^11-
         1/2*n^12);
Fill mpowsum1(13)=
      +sign_(n)*(5461/4-26949/4*n^2+22165/4*n^4-7293/4*n^6+1287/4*n^8-
         143/4*n^10+13/4*n^12-1/2*n^13)
      -5461/4;
Fill mpowsum1(14)=
      +sign_(n)*(38227/2*n-62881/2*n^3+31031/2*n^5-7293/2*n^7+1001/2*
         n^9-91/2*n^11+7/2*n^13-1/2*n^14);
Fill mpowsum1(15)=
      +sign_(n)*(-929569/32+573405/4*n^2-943215/8*n^4+155155/4*n^6-
         109395/16*n^8+3003/4*n^10-455/8*n^12+15/4*n^14-1/2*n^15)
      +929569/32;
Fill mpowsum1(16)=
      +sign_(n)*(-929569/2*n+764540*n^3-377286*n^5+88660*n^7-12155*n^9+
         1092*n^11-70*n^13+4*n^15-1/2*n^16);
Fill mpowsum1(17)=
      +sign_(n)*(3202291/4-15802673/4*n^2+3249295*n^4-1068977*n^6+
         376805/2*n^8-41327/2*n^10+1547*n^12-85*n^14+17/4*n^16-1/2*n^17
         )
      -3202291/4;
Fill mpowsum1(18)=
      +sign_(n)*(28820619/2*n-47408019/2*n^3+11697462*n^5-2748798*n^7+
         376805*n^9-33813*n^11+2142*n^13-102*n^15+9/2*n^17-1/2*n^18);
Fill mpowsum1(19)=
      +sign_(n)*(-221930581/8+547591761/4*n^2-900752361/8*n^4+37041963*
         n^6-26113581/4*n^8+1431859/2*n^10-214149/4*n^12+2907*n^14-969/
         8*n^16+19/4*n^18-1/2*n^19)
      +221930581/8;
Fill mpowsum1(20)=
      +sign_(n)*(-1109652905/2*n+912652935*n^3-900752361/2*n^5+
         105834180*n^7-14507545*n^9+1301690*n^11-82365*n^13+3876*n^15-
         285/2*n^17+5*n^19-1/2*n^20);
#endif
*--#] nndecl.h : 
*--#[ Procedures :
*--#[ adjustsm :
*
#procedure adjustsm(i)
*
*	Adjusts the sum boundaries
*
repeat;
	id	sum`i'(j`i',x1?,x2?)*invfac`i'(x3?,-j`i') = f1(x1,x2,x3,x3-x2);
	if ( match(f1(?a,x4?pos0_)) == 0 );
		id	f1(x1?,x2?,x3?,x4?) = sum`i'(j`i',x1,x2)*f3(x3,-j`i');
	endif;
endrepeat;
id	f3(?a) = invfac`i'(?a);
id	f1(x1?,x2?,x3?,0) = sum`i'(j`i',x1,x2)*invfac`i'(x3,-j`i');
id	f1(x1?,x2?,x3?,n?) = sum`i'(j`i',x1,x3)*invfac`i'(x3,-j`i')
		-sum_(jjj,x2+1,x3,su(jjj))*invfac`i'(x3,-j`i');
id	sum_(jjj,x1?,x2?,su(jjj)) = f1(x1,x2,x2-x1)*su(jjj);
repeat id f1(x1?,x2?,x3?pos_) = f1(x1,x2-1,x3-1)+replace_(jjj,x2);
id	f1(x1?,x2?,0) = replace_(jjj,x2);
id	f1(x1?,x2?,x3?neg_) = 0;
id	f1(x1?,x2?,x3?)*su(jjj) = sum_(jjj,x1,x2,su(jjj));
if ( count(su,1) );
	id	su(n?) = replace_(j`i',n);
	id	S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
	id	den`i'(x1?,x2?) = den(x1+x2);
	id	fac`i'(x1?,x2?) = fac(x1+x2);
	id	invfac`i'(x1?,x2?) = invfac(x1+x2);
	id	sign`i'(x?) = sign_(x);
	id	fac(x?int_) = fac_(x);
	id	invfac(x?int_) = invfac_(x);
	id	den(x?pos_) = 1/x;
	id	den(x?neg_) = 1/x;
	#call subesses(S)
endif;
if ( match(den`i'(x1?pos_,j`i')) );
	id,once,den`i'(x1?pos_,j`i') = den`i'(x1,j`i')*X(x1);
	#call movej(`i',X)
	id	X(x1?) = 1;
endif;
if ( match(den`i'(0,j`i')) );
	id	sum`i'(j`i',n1?pos_,n2?) =
			sum`i'(j`i',1,n2) - sum_(jjj,1,n1-1,su(jjj));
	id	sum_(jjj,x1?,x2?,su(jjj)) = f1(x1,x2,x2-x1)*su(jjj);
	repeat id f1(x1?,x2?,x3?pos_) = f1(x1,x2-1,x3-1)+replace_(jjj,x2);
	id	f1(x1?,x2?,0) = replace_(jjj,x2);
	id	f1(x1?,x2?,x3?neg_) = 0;
	id	f1(x1?,x2?,x3?)*su(jjj) = sum_(jjj,x1,x2,su(jjj));
	if ( count(su,1) );
		id	su(n?) = replace_(j`i',n);
		id	S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
		id	den`i'(x1?,x2?) = den(x1+x2);
		id	fac`i'(x1?,x2?) = fac(x1+x2);
		id	invfac`i'(x1?,x2?) = invfac(x1+x2);
		id	sign`i'(x?) = sign_(x);
		id	fac(x?int_) = fac_(x);
		id	invfac(x?int_) = invfac_(x);
		id	den(x?pos_) = 1/x;
		id	den(x?neg_) = 1/x;
		#call subesses(S)
	endif;
elseif ( match(invfac`i'(n?int_,j`i')) || match(S`i'(R(?a),n?int_,j`i'))
	|| match(fac`i'(n?int_,j`i')) );
	if ( match(invfac`i'(n?int_,j`i')) );
		id,once,invfac`i'(x1?int_,j`i') = invfac`i'(x1,j`i')*X(x1);
	elseif ( match(fac`i'(n?int_,j`i')) );
		id,once,fac`i'(x1?int_,j`i') = fac`i'(x1,j`i')*X(x1);
	else;
		id,once,S`i'(R(?a),x1?int_,j`i') = S`i'(R(?a),x1,j`i')*X(x1);
	endif;
	#call movej(`i',X)
	id	X(x1?) = 1;
	if ( match(den`i'(0,j`i')) );
		id	sum`i'(j`i',n1?pos_,n2?) =
				sum`i'(j`i',1,n2) - sum_(jjj,1,n1-1,su(jjj));
	else;
		id	sum`i'(j`i',n1?pos_,n2?) =
				sum`i'(j`i',0,n2) - sum_(jjj,0,n1-1,su(jjj));
	endif;
	id	sum_(jjj,x1?,x2?,su(jjj)) = f1(x1,x2,x2-x1)*su(jjj);
	repeat id f1(x1?,x2?,x3?pos_) = f1(x1,x2-1,x3-1)+replace_(jjj,x2);
	id	f1(x1?,x2?,0) = replace_(jjj,x2);
	id	f1(x1?,x2?,x3?neg_) = 0;
	id	f1(x1?,x2?,x3?)*su(jjj) = sum_(jjj,x1,x2,su(jjj));
	if ( count(su,1) );
		id	su(n?) = replace_(j`i',n);
		id	S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
		id	den`i'(x1?,x2?) = den(x1+x2);
		id	fac`i'(x1?,x2?) = fac(x1+x2);
		id	invfac`i'(x1?,x2?) = invfac(x1+x2);
		id	sign`i'(x?) = sign_(x);
		id	fac(x?int_) = fac_(x);
		id	invfac(x?int_) = invfac_(x);
		id	den(x?pos_) = 1/x;
		id	den(x?neg_) = 1/x;
		#call subesses(S)
	endif;
endif;
if ( count(sum`i',1) );
	if ( match(invfac`i'(x1?,-j`i')) == 0 );
		if ( match(S`i'(R(?a),x1?,-j`i')) );
			repeat;
				if ( count(X,1) == 0 );
					id sum`i'(j`i',x1?,x2?)*S`i'(R(?a),x3?,-j`i') =
						sum`i'(j`i',x1,x2)*f1(R(?a),x3,-j`i')*X(x3-x2);
					if ( match(X(x?pos0_)) == 0 ) id X(x?) = 1;
				endif;
			endrepeat;
			id	f1(?a) = S`i'(?a);
		elseif ( match(fac`i'(x1?,-j`i')) );
			repeat;
				if ( count(X,1) == 0 );
					id sum`i'(j`i',x1?,x2?)*fac`i'(x3?,-j`i') =
						sum`i'(j`i',x1,x2)*f1(x3,-j`i')*X(x3-x2);
					if ( match(X(x?pos0_)) == 0 ) id X(x?) = 1;
				endif;
			endrepeat;
			id	f1(?a) = fac`i'(?a);
		endif;
		id	X(0) = 1;
		if ( count(X,1) );
			id	sum`i'(j`i',x1?,x2?)*X(x3?) =
				sum`i'(j`i',x1,x2+x3)-sum_(jjj,1,x3,su(x2+jjj));
			id	sum_(jjj,x1?,x2?,su(jjj)) = f1(x1,x2,x2-x1)*su(jjj);
			repeat id f1(x1?,x2?,x3?pos_) = f1(x1,x2-1,x3-1)+replace_(jjj,x2);
			id	f1(x1?,x2?,0) = replace_(jjj,x2);
			id	f1(x1?,x2?,x3?neg_) = 0;
			id	f1(x1?,x2?,x3?)*su(jjj) = sum_(jjj,x1,x2,su(jjj));
if ( match(sum`i'(j`i',0,n?)*den`i'(0,j`i'))  ) print "--4-> %t";
			if ( count(su,1) );
				id	su(n?) = replace_(j`i',n);
				id	S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
				id	den`i'(x1?,x2?) = den(x1+x2);
				id	fac`i'(x1?,x2?) = fac(x1+x2);
				id	invfac`i'(x1?,x2?) = invfac(x1+x2);
				id	sign`i'(x?) = sign_(x);
				id	fac(x?int_) = fac_(x);
				id	invfac(x?int_) = invfac_(x);
				id	den(x?pos_) = 1/x;
				id	den(x?neg_) = 1/x;
				#call subesses(S)
			endif;
		endif;
	endif;
endif;
id	invfac`i'(0,j`i')*invfac`i'(x1?,-j`i') = bino`i'(x1,0,j`i')*invfac(x1);
.sort:boundary adjustment;
id	fac(x?) = fac_(x);
id	invfac(x?) = invfac_(x);
#call simfacs
id	fac_(x?) = fac(x);
id	invfac_(x?) = invfac(x);
repeat id num(n1?)*num(n2?) = num(n1*n2);
id	num(x?) = x;
repeat id j`i'*den`i'(x?,j`i') = 1-x*den`i'(x,j`i');
repeat id j`i'*den`i'(x?,-j`i') = -1+x*den`i'(x,-j`i');
*
#endprocedure
*
*--#] adjustsm : 
*--#[ basis :
*
#procedure basis(S)
*
*   Routine expresses products of harmonic sums into sums of
*   terms, each with a single higher harmonic sum. See appendix A.
*
*   J.Vermaseren,29-oct-1997
*
repeat;
    id,once,`S'(R(?a),n?)*`S'(R(?b),n?) = SS(R(?a),R,R(?b),n);
    repeat id SS(R(x1?,?a),R(?b),R(x2?,?c),n?) =
                +SS(R(x1,?a),R(?b,x2),R(?c),n)
                +SS(R(?a),R(?b,x1),R(x2,?c),n)
                -SS(R(?a),R(?b,x1*sig_(x2)+x2*sig_(x1)),R(?c),n);
    id,SS(R(?a),R(?b),R(?c),n?) = `S'(R(?b,?a,?c),n);
endrepeat;
#endprocedure
*
*--#] basis : 
*--#[ basis2 :
*
#procedure basis2(S)
*
*   Routine expresses products of harmonic sums into sums of
*   terms, each with a single higher harmonic function. See appendix A.
*   This routine is different from basis in that it allows the S function
*   to have two arguments outside the R.
*
*   J.Vermaseren,29-oct-1997
*
repeat;
    id,once,`S'(R(?a),n1?,n2?)*`S'(R(?b),n1?,n2?) = SS(R(?a),R,R(?b),n1,n2);
    repeat id SS(R(x1?,?a),R(?b),R(x2?,?c),n1?,n2?) =
                +SS(R(x1,?a),R(?b,x2),R(?c),n1,n2)
                +SS(R(?a),R(?b,x1),R(x2,?c),n1,n2)
                -SS(R(?a),R(?b,x1*sig_(x2)+x2*sig_(x1)),R(?c),n1,n2);
    id,SS(R(?a),R(?b),R(?c),n1?,n2?) = `S'(R(?b,?a,?c),n1,n2);
endrepeat;
#endprocedure
*
*--#] basis2 : 
*--#[ basisn :
*
#procedure basisn(S,n)
*
*   Routine expresses products of harmonic sums into sums of
*   terms, each with a single higher harmonic function. See appendix A.
*
*   J.Vermaseren,29-oct-1997
*
*repeat;
    id,once,`S'(R(?a),`n')*`S'(R(?b),`n') = SS(R(?a),R,R(?b),`n');
    repeat id SS(R(x1?,?a),R(?b),R(x2?,?c),`n') =
                +SS(R(x1,?a),R(?b,x2),R(?c),`n')
                +SS(R(?a),R(?b,x1),R(x2,?c),`n')
                -SS(R(?a),R(?b,x1*sig_(x2)+x2*sig_(x1)),R(?c),`n');
    id,SS(R(?a),R(?b),R(?c),`n') = `S'(R(?b,?a,?c),`n');
*endrepeat;
#endprocedure
*
*--#] basisn : 
*--#[ conjug :
*
#procedure conjug(n,par)
*
*	Find the conjugate of a harmonic function (first case) or
*	an harmonic function with one or more powers of 1/n (second case).
*	Routine to be used from summit.
*	The algorithm is from appendix B in the paper.
*
*	J.Vermaseren,27-oct-1997
*
Argument Conj;
	id	R(?a)/`n'^j?pos_ = SS(j,?a);
EndArgument;
if ( match(Conj(SS(?a))) );
	Multiply R(0);
	repeat;
		repeat;
			id	Conj(SS(1,?a))*R(?b,m?) = Conj(SS(?a))*R(?b,m+1);
		endrepeat;
		id	Conj(SS(m?,?a))*R(?b,j?) = Conj(SS(m-1,?a))*R(?b,j+1);
		repeat;
			id	Conj(SS(m?pos_,?a))*R(?b) = Conj(SS(m-1,?a))*R(?b,1);
		endrepeat;
		id	Conj(SS(0,?a)) = Conj(SS(?a));
	endrepeat;
	id	Conj(SS) = 1;
	id	R(?a,0) = R(?a);
	id	R = 1;
else if ( match(Conj(R(?a))) );
	Multiply SS(0);
	repeat;
		repeat;
			id	Conj(R(1,?a))*SS(?b,m?) = Conj(R(?a))*SS(?b,m+1);
		endrepeat;
		id	Conj(R(m?,?a))*SS(?b,j?) = Conj(R(m-1,?a))*SS(?b,j+1);
		repeat;
			id	Conj(R(m?pos_,?a))*SS(?b) = Conj(R(m-1,?a))*SS(?b,1);
		endrepeat;
		id	Conj(R(0,?a)) = Conj(R(?a));
	endrepeat;
	id	Conj(R) = 1;
	id	SS(?a,0) = SS(?a);
	id	SS = 1;
	id	SS(m?) = 1/`n'^m;
	id	SS(m?,?a) = R(?a)/`n'^m;
endif;
#if `par' == 0
id	R(?a) = S(R(?a),`n');
#endif
#endprocedure
*
*--#] conjug : 
*--#[ densplit :
*
#procedure densplit(i)
*
*   Procedure splits the fractions.
*   It does this for one summation parameter only, or for N.
*   If the argument is N it does this for N, and if the argument is
*   a number m it does this for jm
*   This routine is optimized for higher powers of the denominators.
*   In that case one uses the sum formula rather than repeated splitting
*   of pairs (which may involve more pattern matching, but the evaluation
*   of the sums requires more time afterwards).
*
#if `i' == N
*
*   Go to the notation with one argument in den.
*   Then separate the N.
*
id  den(x1?,x2?) = den(x1+x2);
SplitArg,(N),den;
*
*   Make simple substitutions.
*   We assume that N/2 and 2*N can occur too.
*   Make that N has always a positive sign inside den.
*
id  den(N) = den(0,N);
id  den(-N) = -den(0,N);
id  den(2*N) = den(0,N)/2;
id  den(-2*N) = -den(0,N)/2;
id  den(N/2) = 2*den(0,N);
id  den(-N/2) = -2*den(0,N);
id  den(x?,N/2) = 2*den(2*x,N);
id  den(x?,-N/2) = -2*den(-2*x,N);
id  den(x?,-N) = -den(-x,N);
id  den(x?,-2*N) = -den(-x/2,N)/2;
id  den(x1?,2*N) = den(x1/2,N)/2;
*
*   Simple partial fractioning with the numerator
*
id  N*den(0,N) = 1;
repeat id N*den(x?,N) = 1-x*den(x,N);
*
*   Notation with power in the first argument
*   Collect the powers
*
id  den(x1?,N) = den(1,x1,N);
repeat id den(x1?,y?,N)*den(x2?,y?,N) = den(x1+x2,y,N);
*
*   Split the fractions. If x is numerical, the delta_ and deltap_ should
*   act immediately. den(x2-x1) is our function and hence a zero there
*   is only a problem if something goes wrong with deltap_.
*
repeat;
    id  den(n1?,x1?,N)*den(n2?,x2?,N) =
        +sum_(jjj,1,n1,binom_(n1+n2-1-jjj,n2-1)*den(jjj,x1,N)
                *den(x1-x2)^(n1+n2-jjj))*sign_(n2)*deltap_(x1-x2)
        +sum_(jjj,1,n2,binom_(n1+n2-1-jjj,n1-1)*den(jjj,x2,N)
                *den(x2-x1)^(n1+n2-jjj))*sign_(n1)*deltap_(x1-x2)
        +delta_(x1-x2)*den(n1+n2,x1,N);
endrepeat;
*
*   Back to regular notation.
*
id  den(n1?,x1?,x2?) = den(x1+x2)^n1;
id  den(x1?,x2?) = den(x1+x2);
*
#else
*
*   We do j`i'
*   First put the den functions to one argument notation.
*
id f?{den,den0,...,den`i'}(x1?,x2?) = den(x1+x2);
id f?{den0,...,den`i'}(x1?) = den(x1);
*
*   Single out the j`i'
*
SplitArg,(j`i'),den;
id  den(x?,j`i') = den`i'(1,x,j`i');
id  den(x?,-j`i') = den`i'(1,x,-j`i');
id  den(j`i') = den`i'(1,0,j`i');
id  den(-j`i') = -den`i'(1,0,j`i');
*
*   Now the first parameter is the power.
*   We recognize only cases with j and -j.
*   Multiples we don't use. (not needed for two loop structure functions)
*   Now do some simplifications with the numerators.
*
id  j`i'*den`i'(1,0,j`i') = 1;
repeat id j`i'*den`i'(1,x?,j`i') = 1-x*den`i'(1,x,j`i');
*
*   Collect the powers
*
repeat id,den`i'(n1?,x1?,x2?)*den`i'(n2?,x1?,x2?) = den`i'(n1+n2,x1,x2);
*
*   The cases den(x+j) and den(x-j) are considered separately, because
*   There is ordering according to the 'biggest' objects, meaning that
*   the sign of N is more important than the sign of j1 than the sign
*   of j2 etc.
*   Hence we need three formula's
*   The function deltap_(x) = 1-delta_(x)
*   It will be replaced later by two theta functions.
*
repeat;
    id  den`i'(n1?,x1?,j`i')*den`i'(n2?,x2?,j`i') =
        +sum_(jjj,1,n1,binom_(n1+n2-1-jjj,n2-1)*den`i'(jjj,x1,j`i')
                *den(x1-x2)^(n1+n2-jjj))*sign_(n2)*deltap_(x1-x2)
        +sum_(jjj,1,n2,binom_(n1+n2-1-jjj,n1-1)*den`i'(jjj,x2,j`i')
                *den(x2-x1)^(n1+n2-jjj))*sign_(n1)*deltap_(x2-x1)
        +delta_(x1-x2)*den`i'(n1+n2,x1,j`i');
endrepeat;
repeat;
    id  den`i'(n1?,x1?,-j`i')*den`i'(n2?,x2?,-j`i') =
        +sum_(jjj,1,n1,binom_(n1+n2-1-jjj,n2-1)*den`i'(jjj,x1,-j`i')
                *den(x1-x2)^(n1+n2-jjj))*sign_(n2)*deltap_(x1-x2)
        +sum_(jjj,1,n2,binom_(n1+n2-1-jjj,n1-1)*den`i'(jjj,x2,-j`i')
                *den(x2-x1)^(n1+n2-jjj))*sign_(n1)*deltap_(x2-x1)
        +delta_(x1-x2)*den`i'(n1+n2,x1,-j`i');
endrepeat;
repeat;
    id  den`i'(n1?,x1?,j`i')*den`i'(n2?,x2?,-j`i') =
        +sum_(jjj,1,n1,binom_(n1+n2-1-jjj,n2-1)*den`i'(jjj,x1,j`i')
                *den(x1+x2)^(n1+n2-jjj))*deltap_(x1+x2)
        +sum_(jjj,1,n2,binom_(n1+n2-1-jjj,n1-1)*den`i'(jjj,x2,-j`i')
                *den(x2+x1)^(n1+n2-jjj))*deltap_(x1+x2)
        +delta_(x1+x2)*den`i'(n1+n2,x1,j`i')*sign_(n2);
endrepeat;
*
*   Cleanup. Go to the 'own' functions.
*
id  den`i'(n1?,x1?,x2?) = den`i'(x1,x2)^n1;
id  delta_(x?) = delta(x);
id  deltap_(x?) = deltap(x);
#endif
*
*   Simple substitutions:
*
id  den(x?pos_) = 1/x;
id  den(x?neg_) = 1/x;
id  sign(x?int_) = sign_(x);
#endprocedure
*
*--#] densplit : 
*--#[ dosign :
*
#procedure dosign
*
*   Deals with all signs.
*   assumes that N, j1,...,jm are all integers.
*
id  sign_(x?) = sign(x);
splitarg sign;
*
*   Each term in the original gets its own function.
*   Flip signs if possible.
*
repeat id sign(n1?,n2?,?a) = sign(n1)*sign(n2,?a);
id  sign(-N) = sign(N);
#do ii = 0,`MAXWEIGHT'
id  sign(-j`ii') = sign(j`ii');
#enddo
*
*   Eliminate squares and sign of integers.
*
id  sign(x?{N,j0,...,j`MAXWEIGHT'})*sign(x?{N,j0,...,j`MAXWEIGHT'}) = 1;
id  sign(x?int_) = sign_(x);
#ifdef 'WITHHALVES'
*
*   If there are halfs, we add all arguments and try again
*
repeat id sign(n1?)*sign(n2?) = sign(n1+n2);
splitarg sign;
repeat id sign(n1?,n2?,?a) = sign(n1)*sign(n2,?a);
id  sign(5*N/2) = sign(N/2);
id  sign(3*N/2) = sign(N)*sign(N/2);
id  sign(-3*N/2) = sign(N/2);
id  sign(-N/2) = sign(N/2)*sign(N);
id  sign(3*N) = sign(N);
id  sign(N)*sign(N) = 1;
id  sign(2*N) = 1;
id  sign(-2*N) = 1;
#endif
*
*   Some fixed simplifications.
*   The function Even(x) = 1/2+sign(x)/2
*   and          Odd(x)  = 1/2-sign(x)/2
*
id  sign(2*N) = 1;
id  sign(3*N) = sign(N);
id  sign(4*N) = 1;
id  Even(N)*sign(N) = Even(N);
id  Odd(N)*sign(N) = -Odd(N);
id  Even(x?even_) = 1;
id  Even(x?odd_) = 0;
id  Odd(x?even_) = 0;
id  Odd(x?odd_) = 1;
#endprocedure
*
*--#] dosign : 
*--#[ extract1 :
*
#procedure extract1(S,S1,x)
*
*	Procedure extracts leading indices 1 from the S-sums with argument x.
*	The extracted indices 1 are left in S1.
*
*	J. Vermaseren, 12-jan-1999
*
repeat;
	if ( match(`S'(R(1,?a),`x')) );
		id	`S'(R(1,?a),`x') = `S'(R(1),R(?a),`x');
		repeat id `S'(R(?b),R(1,?a),`x') = `S'(R(?b,1),R(?a),`x');
		id	`S'(R(?a),R,`x') = `S1'(R(?a),`x');
		id	`S'(R(?b),R(?a),`x') = -`S'(R(?b),`x')*`S'(R(?a),`x')*SR(?b,?a)
				+`S1'(R(?b),`x')*`S'(R(?a),`x');
		#call basis(`S')
		id	SR(?a)*`S'(R(?a),`x') = 0;
		id	SR(?a) = 1;
	endif;
endrepeat;
#endprocedure
*
*--#] extract1 : 
*--#[ extractn :
*
#procedure extractn(S,S1,x)
*
*	Procedure extracts leading indices 1 from the S-sums with argument x.
*	The extracted indices 1 are left as powers of S1(R(1),x)
*
*	J. Vermaseren, 12-jan-1999
*
repeat;
	if ( match(`S'(R(1,?a),`x')) );
		id	`S'(R(1,?a),`x') = `S'(R(1),R(?a),`x');
		repeat id `S'(R(?b),R(1,?a),`x') = `S'(R(?b,1),R(?a),`x');
		id	`S'(R(1),R,`x') = `S1'(R(1),`x');
		id	`S'(R(1,?a),R(?b),`x') = `S'(R(1),R(?a,?b),`x')/(nargs_(?a)+1);
		id	`S'(R(1),R(?a),`x') = -`S'(R(1),`x')*`S'(R(?a),`x')*SR(1,?a)
				+`S1'(R(1),`x')*`S'(R(?a),`x');
		#call basis(`S')
		id	SR(?a)*`S'(R(?a),`x') = 0;
		id	SR(?a) = 1;
	endif;
endrepeat;
#endprocedure
*
*--#] extractn : 
*--#[ flipj :
*
#procedure flipj(i)
*
*   Reverses the direction of summation
*
id  sum`i'(j`i',x1?,x2?) = sum`i'(0,x2-x1)*replace_(j`i',x2-j`i');
id  sum`i'(x1?,x2?) = sum`i'(j`i',x1,x2);
*
*   The special functions have to be redone
*
id  f?{den`i',fac`i',invfac`i'}(x1?,x2?) = f(x1+x2);
id  bino`i'(x1?,x2?,x3?) = bino`i'(x1,x2+x3);
id  S`i'(x1?,x2?,x3?) = S`i'(x1,x2+x3);
SplitArg,(j`i'),den`i',fac`i',invfac`i',S`i',bino`i';
id  f?{den`i',fac`i',invfac`i'}(x2?) = f(0,x2);
id  S`i'(x1?,x2?) = S`i'(x1,0,x2);
id  bino`i'(x1?,x2?) = bino`i'(x1,0,x2);
id	bino`i'(x1?,x2?,-j`i') = bino`i'(x1,x1-x2,j`i');
*
*   Truncated version of dosign. It is only needed for the j`i' related
*   objects.
*
SplitArg,sign`i';
repeat id sign`i'(x1?,x2?,?a) = sign(x1)*sign`i'(x2,?a);
id  sign`i'(-j`i') = sign`i'(j`i');
id  sign(x?int_) = sign_(x);
id  sign(j`i') = sign`i'(j`i');
id  sign(-j`i') = sign`i'(j`i');
id  sign(x?{N,j1,...,j`MAXWEIGHT'})*sign(x?{N,j1,...,j`MAXWEIGHT'}) = 1;
repeat id sign(n1?number_)*sign(n2?number_) = sign(n1+n2);
id  sign(x?int_) = sign_(x);
*
#endprocedure
*
*--#] flipj : 
*--#[ makei :
*
#procedure makei(mi)
*
*   Routine singles out the j`mi' summation parameter and all
*   functions that contain this parameter (and that are recognized
*   by the system of course).
*   First all functions are converted into the generic functions
*
#if `mi' == 0
*
*   The zero case is for special applications. In that case we only
*   do this one and nothing more.
*   Collapse everything into the base notation
*
repeat id f?{theta,theta0,delta,delta0,deltap,deltap0,den,den0,fac,fac0,invfac,invfac0}(x1?,x2?,?a) = f(x1+x2,?a);
repeat id f?{S,S0}(x1?,x2?,x3?,?a) = f(x1,x2+x3,?a);
id  theta0(x?) = theta(x);
id  delta0(x?) = delta(x);
id  deltap0(x?) = deltap(x);
id  den0(x?) = den(x);
id  fac0(x?) = fac(x);
id  invfac0(x?) = invfac(x);
id  S0(?a) = S(?a);
#else
*
*   In this case the `mi' objects and all lower objects are first
*   converted back to the base notation. This goes best with sets,
*   because otherwise there would be many id statement.
*
repeat id f?{theta,theta0,...,theta`mi'\
    ,delta,delta0,...,delta`mi',deltap,deltap0,...,deltap`mi'\
    ,den,den0,...,den`mi',fac,fac0,...,fac`mi'\
    ,invfac,invfac0,...,invfac`mi'}(x1?,x2?,?a) = f(x1+x2,?a);
repeat id f?{S,S0,...,S`mi'}(x1?,x2?,x3?,?a) =
                f(x1,x2+x3,?a);
id  f?{theta0,...,theta`mi'}(x?) = theta(x);
id  f?{delta0,...,delta`mi'}(x?) = delta(x);
id  f?{deltap0,...,deltap`mi'}(x?) = deltap(x);
id  f?{den0,...,den`mi'}(x?) = den(x);
id  f?{fac0,...,fac`mi'}(x?) = fac(x);
id  f?{invfac0,...,invfac`mi'}(x?) = invfac(x);
id  f?{S0,...,S`mi'}(?a) = S(?a);
#endif
*
*   Put the built-in equivalents also into the base functions.
*   They are sometimes used to convert numerical arguments immediately.
*   This is especially useful with delta_, theta_ and sign_ functions.
*
id  fac_(x?) = fac(x);
id  invfac_(x?) = invfac(x);
id  delta_(x?) = delta(x);
id  deltap_(x?) = deltap(x);
id  theta_(x?) = theta(x);
id  sign_(x?) = sign(x);
*
*   Now the splitarg singles out the j`mi'
*   We make sure that the 0 is not forgotten (the argument is already `split')
*
SplitArg,(j`mi'),delta,deltap,theta,den,fac,invfac,S;
id  f?{delta,deltap,theta,den,fac,invfac}(j`mi') = f(0,j`mi');
id  f?{delta,deltap,theta,den,fac,invfac}(-j`mi') = f(0,-j`mi');
id  S(x1?,j`mi') = S(x1,0,j`mi');
id  S(x1?,-j`mi') = S(x1,0,-j`mi');
*
*   Create the `mi' functions
*   Those will be the exclusive object of study.
*
id  f?{delta,deltap,theta,den,fac,invfac}[n](x1?,j`mi') =
        {delta`mi',deltap`mi',theta`mi',den`mi',fac`mi',invfac`mi'}[n](x1,j`mi');
id  f?{delta,deltap,theta,den,fac,invfac}[n](x1?,-j`mi') =
        {delta`mi',deltap`mi',theta`mi',den`mi',fac`mi',invfac`mi'}[n](x1,-j`mi');
id  S(x1?,x2?,j`mi') = S`mi'(x1,x2,j`mi');
id  S(x1?,x2?,-j`mi') = S`mi'(x1,x2,-j`mi');
id  sum(j`mi',?a) = sum`mi'(j`mi',?a);
id  sign(j`mi') = sign`mi'(j`mi');
*
*   Now we have to fix the proper sign on den`mi'
*
#call normden(`mi')
*
#endprocedure
*
*--#] makei : 
*--#[ movej :
*
#procedure movej(i,X)
*
*   Makes a translation of j`i'+x -> j`i' with x the argument of X
*
id  sum`i'(j`i',x1?,x2?)*`X'(x3?) = sum`i'(x1+x3,x2+x3)*replace_(j`i',j`i'-x3);
id  sum`i'(x1?,x2?) = sum`i'(j`i',x1,x2);
*
*   We have to redo some of the special functions
*
id  f?{den`i',fac`i',invfac`i',sign`i'}(x1?,x2?) = f(x1+x2);
id  S`i'(x1?,x2?,x3?) = S`i'(x1,x2+x3);
SplitArg,(j`i'),den`i',fac`i',invfac`i',S`i';
id  f?{den`i',fac`i',invfac`i'}(x2?) = f(0,x2);
id  S`i'(x1?,x2?) = S`i'(x1,0,x2);
*
*   Now a truncated version of dosign. We do not need the whole thing
*
SplitArg,sign`i';
repeat id sign`i'(x1?,x2?,?a) = sign(x1)*sign`i'(x2,?a);
id  sign`i'(-j`i') = sign`i'(j`i');
id  sign(-j`i') = sign`i'(j`i');
id  sign(j`i') = sign`i'(j`i');
id  sign(x?int_) = sign_(x);
id  sign(x?{N,j1,...,j`MAXWEIGHT'})*sign(x?{N,j1,...,j`MAXWEIGHT'}) = 1;
repeat id sign(n1?number_)*sign(n2?number_) = sign(n1+n2);
id  sign(x?int_) = sign_(x);
*
#endprocedure
*
*--#] movej : 
*--#[ normden :
*
#procedure normden(ndi)
*
*   Fix a proper sign on the den function.
*   Hierarchy: Most important is N, then j1, then j2 etc
*   We use f1 as a auxiliary for functions that have the proper sign already
*
SplitArg,(N),den`ndi';
id  den`ndi'(N,x1?) = f1(N,x1);
id  den`ndi'(-N,x1?) = -f1(N,-x1);
id  den`ndi'(x2?,N,x1?) = f1(x2+N,x1);
id  den`ndi'(x2?,-N,x1?) = -f1(-x2+N,-x1);
#do ndii = 1,`ndi'-1
if ( count(den`ndi',1) );
    SplitArg,(j`ndii'),den`ndi';
    id  den`ndi'(j`ndii',x1?) = f1(j`ndii',x1);
    id  den`ndi'(-j`ndii',x1?) = -f1(j`ndii',-x1);
    id  den`ndi'(x2?,j`ndii',x1?) = f1(x2+j`ndii',x1);
    id  den`ndi'(x2?,-j`ndii',x1?) = -f1(-x2+j`ndii',-x1);
#enddo
    id  den`ndi'(x1?,-j`ndi') = -den`ndi'(-x1,j`ndi');
#do ii = 1,`ndi'-1
endif;
#enddo
id  f1(?a) = den`ndi'(?a);
#endprocedure
*
*--#] normden : 
*--#[ simfacs :
*
#procedure simfacs
*
*   Procedure tries to simplify combinations of fac*invfac
*   It looks for combinations where the difference of the arguments
*   is a constant integer. Those can be worked out.
*
*   The function f1 is the factorial under consideration (we do one by one)
*   The function f2 is to put away the fac functions that are not having
*   a simplification.
*   The function f3 puts away the invfac functions that do not match with
*   the current fac (f1)
*   f4 registers the matches. Those are pairs that need to be worked out.
*
*   The function num stands for composite numerators (num(x)=x)
*   The function den for denominators (den(x) = 1/x)
*   The calling routine should decide when these are processed further
*   to avoid a buildup of terms at the wrong moment.
*
*   J.Vermaseren 6-jun-1998
*
id  fac_(x?)*invfac_(x?) = 1;
repeat;
    id,once,fac_(x?) = f1(x);
    repeat;
        id  f1(x1?)*invfac_(x2?) = f1(x1,x2,x1-x2);
        id  f1(x1?,x2?,x3?int_) = f4(x1,x3);
        id  f1(x1?,x2?,x3?) = f1(x1)*f3(x2);
    endrepeat;
    id  f3(x?) = invfac_(x);
    id  f1(x?) = f2(x);
endrepeat;
repeat id f4(x1?,x2?pos_) = f4(x1-1,x2-1)*num(x1);
repeat id f4(x1?,x2?neg_) = f4(x1+1,x2+1)*den(x1+1);
id  f4(x1?,0) = 1;
id  num(x?)*den(x?) = 1;
id  f2(x?) = fac_(x);
#endprocedure
*
*--#] simfacs : 
*--#[ subesses :
*
#procedure subesses(S)
*
*   Procedure evaluates the harmonic functions with a numerical last argument
*   into their numerical value. The symbolic ones are untouched of course.
*
*   J.Vermaseren,29-oct-1997
*
*   All operations are done in the arguments to ensure continuous sorting
*   If this would not be done, there would be many terms.
*
id  `S'(R(?a),n?pos_) = acc1(`S'(?a,n));
id  `S'(R(?a),n?neg0_) = 0;
repeat;
    argument acc1;
        id  `S'(m?pos_,?a,n?) = sum_(jjj,1,n,`S'(?a,jjj)/jjj^m);
        id  `S'(n?) = 1;
    endargument;
    argument acc1;
        id  `S'(m?neg_,?a,n?) = sum_(jjj,1,n,`S'(?a,jjj)*sign_(jjj)*jjj^m);
        id  `S'(n?) = 1;
    endargument;
endrepeat;
id  acc1(x?) = x;
#endprocedure
*
*--#] subesses : 
*--#[ sum2bin :
*
#procedure sum2bin(i)
*
*   Procedure deals with summation formulae with two binomial coefficients
*   and a sign_ function. The central identity is
*   sum_(jjj,0,n,sign_(jjj)*binom_(n,jjj)*
*                       binom_(n+jjj,m+jjj)*f(m+jjj)) =
*   sum_(jjj,0,n,sign_(jjj)*binom_(n,jjj)*
*                       binom_(n+jjj,m+jjj)*fC(m+jjj))*sign_(m+n+1)
*   with the condition that 0 <= m <= n. fC is the conjugate function of f.
*   When m = 0, the sum runs from 1.
*
*
*   Routine still under construction
*
#endprocedure
*
*--#] sum2bin : 
*--#[ suminfm :
*
#procedure suminfm(i)
*
*	Procedure does sums of the type
*	sum(j,1,inf)*S(R(?a),n1+j)/j^n2
*	The central relation is:
*	F(n1)=sum(j,1,inf)*S(R(a1,?a),n1+j)/j^n2
*	    =F(n1-1)+sum(j,1,inf)*S(R(?a),n1+j)/(n1+j)^a1/j^n2
*
*	Bug repaired 14-jan-1999
*
SplitArg,(j`i'),S`i';
id	den`i'(j`i') = 1/j`i';
id	den`i'(0,j`i') = 1/j`i';
id	sum`i'(j`i',1,inf)*sign`i'(j`i')*S`i'(R(?a),n1?,j`i')/j`i'^n2?pos_ =
			SS(R(?a),R,-n2,n1);
id	sum`i'(j`i',1,inf)*S`i'(R(?a),n1?,j`i')/j`i'^n2?pos_ = SS(R(?a),R,n2,n1);
if ( count(S`i',1,fac`i',1,bino`i',1,den`i',1,j`i',1) );
	id	SS(R(?a),R,n2?pos_,n1?) = sum`i'(j`i',1,inf)*S`i'(R(?a),n1+j`i')*den`i'(0,j`i')^n2;
	id	SS(R(?a),R,n2?neg_,n1?) = sum`i'(j`i',1,inf)*S`i'(R(?a),n1+j`i')
			*sign`i'(j`i')*den`i'(0,j`i')^(-n2);
endif;
repeat;
id	SS(R(n?,?a),R(?b),n2?,n1?) = S(R(n2,n,?a),inf)*S(R(?b),n1)
		+ sum_(jjj,1,abs_(n2),binom_(abs_(n2)+abs_(n)-1-jjj,abs_(n)-1)*
				SS(R(?a),R(?b,(abs_(n2)+abs_(n)-jjj)*sig_(n)),jjj*sig_(n2*n),n1)*sign_(jjj))
					*sign_(n2)
		+ sum_(jjj,1,abs_(n),binom_(abs_(n2)+abs_(n)-1-jjj,abs_(n2)-1)*
				S(R(sig_(n*n2)*jjj,?a),inf)*
				S(R(?b,(abs_(n2)+abs_(n)-jjj)*sig_(n2)),n1))*sign_(n2)
		- sum_(jjj,1,abs_(n),binom_(abs_(n2)+abs_(n)-1-jjj,abs_(n2)-1)*
				S(R(?b,(abs_(n2)+abs_(n)-jjj)*sig_(n2),jjj*sig_(n*n2),?a),n1))
				*sign_(n2)
		;
endrepeat;
id	SS(R,R(?b),n2?,n1?) = S(R(n2),inf)*S(R(?b),n1);
id	S(R,?a) = 1;
#endprocedure
*
*--#] suminfm : 
*--#[ summer :
*
#procedure summer(n)
*
*   The summation routine that runs the show.
*   Routine works its way successively through all sums, starting at
*   the highest sum which is indicated by `n'.
*   Notice that for a large number of complicated nested sums this
*   is not going to be fast.
*
#do i = `n',1,-1
*
*   Introduce the proper variables for sum`i'
*
#call makei(`i')
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
.sort:introduction of `i';
*
*   Synchronize the sum
*
#call synch(`i')
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
.sort:Presum `i';

*
*   Now some cleaning up
*
#do ii = `i'-1,1,-1
#call densplit(`ii')
#enddo
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
#call densplit(N)
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
.sort:densplit-`i';
#do ii = `i'-1,1,-1
#call theta(`ii')
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
#enddo
#call theta(N)
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
id	sign(x?number_) = sign_(x);
.sort:theta cleanup;
*
*   Final regularization of the sum
*   Introduction of the rather dangerous binomials.
*
#call sumreg(`i')

SplitArg,((inf)),sum`i';
id	sum`i'(x1?,x2?,x3?,inf) = sum`i'(x1,x2,inf);
if ( match(sum`i'(j`i',x1?!number_,inf)*den`i'(0,j`i')*S`i'(R(?a),x2?!{0,0},j`i')) );
	Print +f "<1> %t";
	id	den`i'(x1?,x2?) = den`i'(x1+x2);
	id	sum`i'(j`i',x1?,inf)*S`i'(R(?a),x2?!{0,0},j`i') =
			sum`i'(j`i'+x2,x1+x2,inf)*S`i'(R(?a),0,j`i'+x2)*replace_(j`i',j`i'-x2);
	SplitArg,((j`i')),den`i',sign`i';
	id	den`i'(j`i') = den`i'(0,j`i');
	id	sign`i'(x?,j`i') = sign`i'(j`i')*sign(x);
	Print +f "<2> %t";
endif;
*B   sum`i',j`i',S`i',bino`i',sign`i',fac`i',invfac`i',den`i';
*Print +f +s;

.sort:check sums;
*
*   Now do the sums
*
#call summit(`i')
if ( count(sum`i',1) );
	Print +f "<1> %t";
	if ( match(den`i'(0,j`i')) );
	id	S`i'(R(?a),x1?,x2?) = S`i'(R(?a),x1+x2);
		#call suminfm(`i')
	else;
		#call summinf(`i')
	endif;
	Print +f "<2> %t";
endif;
.sort 
*
*   And a little bit of cleaning up
*
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
#call subesses(S)
.sort:summit `i';
*
*   Now some major cleaning up
*
#do ii = `i'-1,1,-1
#call densplit(`ii')
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
#enddo
#call densplit(N)
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
.sort:densplit-`i';
#do ii = `i'-1,1,-1
#call theta(`ii')
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
#enddo
#call theta(N)
#ifdef `EXTRASUMMER'
;`EXTRASUMMER'
#endif
id	sign(x?number_) = sign_(x);

*Print +f +s;

.sort:do theta (`i');
*
*   End of sum`i'
*
#enddo
#endprocedure
*
*--#] summer : 
*--#[ summinf :
*
#procedure summinf(i)
*
*   Sums of the type sum(j,1,inf)*S(R(?a),j)*den(x+j)^n0 [*sign(j)]
*   Routine by J.Vermaseren, 8-jul-1998
*
id  den`i'(x?,j`i') = den`i'(1,x,j`i');
repeat id den`i'(n1?,x?,j`i')*den`i'(n2?,x?,j`i') = den`i'(n1+n2,x,j`i');
id  sum`i'(j`i',1,inf)*S`i'(R(?a),0,j`i')*den`i'(n?,n1?,j`i')*sign`i'(j`i') =
                        SS(R(?a),-n,n1)*RR(n1,1,0);
id  sum`i'(j`i',1,inf)*S`i'(R(?a),0,j`i')*den`i'(n?,n1?,j`i') =
                        SS(R(?a),n,n1)*RR(n1,1,0);
id  sum`i'(j`i',0,inf)*S`i'(R(?a),0,j`i')*den`i'(n?,n1?,j`i')*sign`i'(j`i') =
                        SS(R(?a),-n,n1)*RR(n1,1,0);
id  sum`i'(j`i',0,inf)*S`i'(R(?a),0,j`i')*den`i'(n?,n1?,j`i') =
                        SS(R(?a),n,n1)*RR(n1,1,0);
repeat;
    id  SS(R(n1?,?a),n0?,x?)*RR(x?,?b,ns?,np?) =
            +S(R(n0),inf)*S(R(n1,?a),inf)*RR(x,?b,ns*sig_(n0),np)
            -sum`i'(j`i',1,inf)*sign1(j`i')^theta_(-n1)*den`i'(abs_(n1),0,j`i')
                *S`i'(R(?a),j`i')*S`i'(R(n0),j`i')*RR(x,?b,ns*sig_(n0),np)
            +sum_(k,1,abs_(n1),binom_(abs_(n0)+abs_(n1)-1-k,abs_(n0)-1)
                *sign(n1-k)*S(R(sig_(n0)*sig_(n1)*k,?a),inf)
                *RR(x,?b,ns,np+abs_(n0)+abs_(n1)-k))
            -sum_(k,1,abs_(n1),binom_(abs_(n0)+abs_(n1)-1-k,abs_(n0)-1)
                *sign(n1+k)*S(R(sig_(n0)*sig_(n1)*k,?a),inf)
                *RR(x,?b,ns*sig_(n0),np)*S(RR(n0+sig_(n0)*(abs_(n1)-k)),x))
            +sum_(k,1,abs_(n0),binom_(abs_(n0)+abs_(n1)-1-k,abs_(n1)-1)
                *sign(n1)*SS(R(?a),sig_(n0)*sig_(n1)*k,x)
                *RR(x,?b,ns,np+abs_(n0)+abs_(n1)-k))
            -sum_(k,1,abs_(n0),binom_(abs_(n0)+abs_(n1)-1-k,abs_(n1)-1)
                *sign(n1)*SS(R(?a),k*sig_(n0)*sig_(n1),x)
                *RR(x,?b,ns*sig_(n0),np,sig_(n0),abs_(n0)+abs_(n1)-k))
            ;
endrepeat;
id  SS(R,n0?,x?)*RR(x?,?b,ns?,np?) = RR(x,?b,ns*sig_(n0),np)
            *(S(R(n0),inf)-S(RR(n0),x));
id  S`i'(R,?a) = 1;
id  S(R,?a) = 1;
if ( count(S`i',1) > 1 );
  #call basis(S`i')
endif;
if ( count(S`i',1) == 1 );
    id  sum`i'(j`i',1,inf)*sign1(j`i')*S`i'(R(?a),j`i')*den`i'(n?,0,j`i') =
                S(R(-n,?a),inf);
    id  sum`i'(j`i',1,inf)*S`i'(R(?a),j`i')*den`i'(n?,0,j`i') = S(R(n,?a),inf);
endif;
#call basis(S);
if ( match(RR(x?,?b)*S(RR(?a),x?)) == 0 );
    id  RR(x?,?b) = RR(x,?b)*S(RR,x);
endif;
repeat id RR(x?,n1?,n2?,?b,ns?,np?)*S(RR(?a),x?) =
                RR(x,n1,n2,?b)*S(RR(ns*np,?a),x);
id  RR(x?,ns?,np?)*S(RR(?a),x?) = S(R(?a),x)*den(x)^np*sign(x)^theta_(-ns);
id  sign(x?)*sign(x?) = 1;
id  sign(x?number_) = sign_(x);
id  den(x?number_) = 1/x;
id  S(R,?a) = 1;
*
#endprocedure
*
*--#] summinf : 
*--#[ summit :
*
#procedure summit(i)
*
*   Do the actual sums. Of course much is delegated.
*   Note: in some cases we have sums to infinity. We use the symbol inf
*   for infinity. One should be a bit careful with j+inf -> inf because
*   if j is a summation parameter that can also go to infinity we may want
*   to obtain 2*inf in due time. This regularizes properly for
*   S(R(1),n*inf) => S(R(1),inf) + ln_(n)
*   For more details, see the paper.
*

*B	sum`i',j`i',fac`i',bino`i',invfac`i',den`i',S`i',sign`i';
*Print +f +s;
*.end

if ( count(sum`i',1) );  * No need if no sum
*
*   First set up a mechanism by which we can go through the thing again
*   in case we obtain a suitable simplification.
*   We should be careful not to put a direct repeat for the occurrence of
*   sum`i', because in the case that it cannot do the sum it would hang in
*   the loop. Hence we will only send it through the loop in the case something
*   very useful happened.
*
  Multiply x;
  repeat;
  if ( count(x,1) );
  id x = 1;
*
*   Double binomials.
*
  if ( ( count(bino`i',1) == 2 ) && ( count(sign`i',1) == 1 )
    && ( count(fac`i',1,invfac`i',1) == 0 ) );
    if ( count(sign`i',1) == 1 );
      #call sum2bin(`i')
    else;
    endif;
*
*   Conjugations
*
  elseif ( ( count(bino`i',1) == 1 ) && ( count(sign`i',1) == 1 )
    && ( count(fac`i',1,invfac`i',1) == 0 ) );  * conjugation
    id  den`i'(0,j`i') = 1/j`i';
*new
	if ( ( count(j`i',1) > 0 ) && ( count(den`i',1) == 0 ) && ( count(S`i',1) == 1 ) );
		id	sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*
						S`i'(R(?a),n?,-j`i')*j`i'^n1? =
			sum`i'(j`i',0,n)*sign(n)*sign`i'(j`i')*bino`i'(n,0,j`i')
						*S`i'(R(?a),0,j`i')*(n-j`i')^n1;
		id	sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*
						S`i'(R(?a),n?,-j`i')*j`i'^n1? =
			sum`i'(j`i',0,n)*sign(n)*sign`i'(j`i')*bino`i'(n,0,j`i')
						*S`i'(R(?a),0,j`i')*(n-j`i')^n1;
	endif;
    repeat;
      if ( ( count(j`i',1) > 0 ) && ( count(sum`i',1,S`i',1) == 2 ) );
        if ( count(j`i',1) >= 0 );
            id sum`i'(j`i',1,n?) = sum`i'(j`i',0,n)-replace_(j`i',0);
			id S`i'(R(?a),0,0) = 0;
			id bino`i'(n?,0,0) = 1;
			id sign`i'(0) = 1;
        endif;
        id  sum`i'(j`i',0,n?)*S`i'(R(n1?pos_,?a),0,j`i')*bino`i'(n?,0,j`i')
                *sign`i'(j`i')*j`i'^x?pos_ =
			+n*sum`i'(j`i',0,n)*S`i'(R(n1,?a),0,j`i')*bino`i'(n,0,j`i')
				*sign`i'(j`i')*j`i'^x/j`i'
			-n*sum`i'(j`i',0,n-1)*S`i'(R(n1,?a),0,j`i')*bino`i'(n-1,0,j`i')
				*sign`i'(j`i')*j`i'^x/j`i'*theta(n-1);
      endif;
    endrepeat;
*endnew
    if ( count(den`i',1) == 0 );
      if ( ( count(S`i',1) == 1 ) && ( match(S`i'(R(n1?pos_),0,j`i'))
      #do ia = 2,`MAXWEIGHT'
        || match(S`i'(R(<n1?pos_>,...,<n`ia'?pos_>),0,j`i'))
      #enddo
       ) );
        if ( count(j`i',1) == 0 );
          id  sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            *S`i'(R(?a),0,j`i') = -Conj(R(?a))*rep(j`i',n);
          id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            *S`i'(R(?a),0,j`i') = -Conj(R(?a))*rep(j`i',n);
        else;
          id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            *S`i'(R(?a),0,j`i')/j`i'^nn?pos_ =
              -Conj(R(?a)/j`i'^nn)*rep(j`i',n);
        endif;
        #call conjug(j`i',0)
        id  1/j`i' = den(j`i');
        id  rep(j`i',n?) = replace_(j`i',n);
      elseif ( count(S`i',1) == 0 );
        if ( count(j`i',1) == 0 );
          id  sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            = delta(n);
          id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            = -theta(n-1);
        else if ( count(j`i',1) < 0 );
          id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')
            /j`i'^nn? = -y^nn*S`i'(n);
          repeat id y^nn?pos_*S`i'(?a) = y^nn/y*S`i'(1,?a);
          id  S`i'(?a,n?) = S(R(?a),n);
        else if ( count(j`i',1) > 0 );
          id,only,sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i'^3 =
            sum`i'(j`i',0,n-1)*sign`i'(j`i')*bino`i'(n-1,0,j`i')*(j`i'+1)^2;
          id,only,sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i'^3 =
            sum`i'(j`i',0,n-1)*sign`i'(j`i')*bino`i'(n-1,0,j`i')*(j`i'+1)^2;
          id,only,sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i'^2 =
            sum`i'(j`i',0,n-1)*sign`i'(j`i')*bino`i'(n-1,0,j`i')*(j`i'+1);
          id,only,sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i'^2 =
            sum`i'(j`i',0,n-1)*sign`i'(j`i')*bino`i'(n-1,0,j`i')*(j`i'+1);
          id,only,sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i' =
                 -n*delta(n-1);
          id,only,sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*j`i' =
                 -n*delta(n-1);
          id  sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i') = delta(n);
        endif;
      elseif ( ( ( count(S`i',1) == 1 ) && ( match(S`i'(R(n1?pos_),n?,-j`i'))
      #do ia = 2,`MAXWEIGHT'
        || match(S`i'(R(<n1?pos_>,...,<n`ia'?pos_>),n?,-j`i'))
      #enddo
       ) )
      || ( ( count(S`i',1) == 2 ) && ( match(S`i'(R(n1?pos_),0,j`i'))
      #do ia = 2,`MAXWEIGHT'
        || match(S`i'(R(<n1?pos_>,...,<n`ia'?pos_>),0,j`i'))
      #enddo
       ) && ( match(S`i'(R(n1?pos_),n?,-j`i'))
      #do ia = 2,`MAXWEIGHT'
        || match(S`i'(R(<n1?pos_>,...,<n`ia'?pos_>),n?,-j`i'))
      #enddo
       ) ) );
        #call sumnmic(`i')
      else;
        id  1/j`i' = den`i'(0,j`i');
      endif;
    else;
      id  1/j`i' = den`i'(0,j`i');
    endif;
*
*   A number of special sums
*
  elseif ( ( count(bino`i',1) == 0 ) && ( count(fac`i',1,invfac`i',1) == 2 ) );
    #call sumspec(`i')
*
*   no binomials or factorials
*
  elseif ( count(bino`i',1,fac`i',1,invfac`i',1) == 0 );
*
*   Forms involving S(R(...),n-j)
*
    if ( match(S`i'(R(?a),x1?,-j`i')) );
      repeat id j`i'*den`i'(x?,j`i') = 1-den`i'(x,j`i')*x;
      id  den`i'(x1?,j`i') = den`i'(1,x1,j`i');
      repeat id den`i'(n1?,x1?,j`i')*den`i'(n2?,x1?,j`i')
          = den`i'(n1+n2,x1,j`i');
*      if ( ( count(den`i',1) == 0 ) && ( count(j`i',1) == 0 ) );
      if ( count(den`i',1) == 0 );
        if ( count(S`i',1) == 2 );
          #call sumnmi0(`i')
        endif;
        id  S`i'(R,0,0) = 0;
        id  S`i'(R,?a) = 1;
        if ( count(S`i',1) == 1 );
          id  sum`i'(j`i',n1?,n?)*S`i'(R(?a),n?,-j`i')*sign`i'(j`i')*j`i'^x? =
              sum`i'(j`i',0,n-n1)*S`i'(R(?a),0,j`i')*sign`i'(j`i')*sign(n)
					*(n-j`i')^x;
          id  sum`i'(j`i',n1?,n?)*S`i'(R(?a),n?,-j`i')*j`i'^x? =
              sum`i'(j`i',0,n-n1)*S`i'(R(?a),0,j`i')*(n-j`i')^x;
          Multiply x;
        elseif ( ( count(S`i',1) == 0 ) && ( count(sum`i',1) == 1 ) );
          Multiply x;
        endif;
      elseif ( count(den`i',1) == 1 );
        #call sumnmii(`i')
      endif;
    elseif ( match(S`i'(R(?a),x1?,j`i')) == 1 );
*
*   Forms involving a single S(R(...),a+j)
*
      id  den`i'(x1?,j`i') = den`i'(1,x1,j`i');
      repeat id den`i'(n1?,x1?,j`i')*den`i'(n2?,x1?,j`i')
          = den`i'(n1+n2,x1,j`i');
      if ( count(den`i',1) == 1 );
        if ( count(sign`i',1) );
          id  sum`i'(j`i',x1?,x2?)*den`i'(n?,x3?,j`i')
              *S`i'(R(?a),x3?,j`i')*sign`i'(j`i') =
            S(R(-n,?a),x2+x3)-S(R(-n,?a),x1+x3-1);
        else;
          id  sum`i'(j`i',x1?,x2?)*den`i'(n?,x3?,j`i')
              *S`i'(R(?a),x3?,j`i') =
            S(R(n,?a),x2+x3)-S(R(n,?a),x1+x3-1);
        endif;
      elseif ( ( count(den`i',1) == 0 ) && ( count(j`i',1) == 0 ) );
        id  sum`i'(j`i',x1?{0,1},x2?)*S`i'(R(n1?,?a),0,j`i')*sign`i'(j`i') =
          sign(x2)*S(R(n1,?a),x2)/2+S(R(-n1,?a),x2)/2;
        repeat;
          id  sum`i'(j`i',x1?{0,1},x2?)*S`i'(R(n1?pos_,?a),0,j`i') =
            (x2+1)*S(R(n1,?a),x2)
            -sum`i'(j`i',1,x2)*S`i'(R(?a),0,j`i')*delta_(n1-1)
            -S(R(n1-1,?a),x2)*theta_(n1-2);
          id  sum`i'(j`i',x1?{0,1},x2?)*S`i'(R(n1?neg_,?a),0,j`i') =
            (x2+1)*S(R(n1,?a),x2)
            -sum`i'(j`i',1,x2)*S`i'(R(?a),0,j`i')*sign`i'(j`i')*delta_(n1+1)
            -S(R(n1+1,?a),x2)*theta_(-n1-2);
          id  sum`i'(j`i',x1?{0,1},x2?)*S`i'(R(n1?,?a),0,j`i')*sign`i'(j`i') =
            sign(x2)*S(R(n1,?a),x2)/2+S(R(-n1,?a),x2)/2;
        endrepeat;
        if ( match(S`i'(R,n?,j`i')) );
          id  S`i'(R,?a) = 1;
          id  sum`i'(j`i',x1?,x2?)*sign`i'(j`i') = sign(x1)/2+sign(x2)/2;
          id  sum`i'(j`i',x1?,x2?) = x2+1-x1;
        endif;
      elseif ( ( count(den`i',1) == 0 ) && ( count(j`i',1) > 0 ) );
        #call sumposp(`i')
      endif;
    elseif ( count(S`i',1) == 0 );
*
*   Forms involving no S at all. -> only powers of j, den, sign
*
      id  den`i'(x1?,j`i') = den`i'(1,x1,j`i');
      repeat id den`i'(n1?,x1?,j`i')*den`i'(n2?,x1?,j`i')
          = den`i'(n1+n2,x1,j`i');
      if ( count(den`i',1) == 1 );
        if ( count(sign`i',1) );
          id  sum`i'(j`i',x1?,x2?)*den`i'(n?,x3?,j`i')*sign`i'(j`i') =
            S(R(-n),x2+x3)-S(R(-n),x1+x3-1);
        else;
          id  sum`i'(j`i',x1?,x2?)*den`i'(n?,x3?,j`i') =
            S(R(n),x2+x3)-S(R(n),x1+x3-1);
        endif;
      elseif ( count(den`i',1) == 0 );
		if ( count(j`i',1) > 0 );
          id  sum`i'(j`i',x1?,x2?)*sign`i'(j`i')*j`i'^n? =
				mpowsum(n,x2)-mpowsum(n,x1-1)*theta_(x1-1);
          id  sum`i'(j`i',x1?,x2?)*j`i'^n? =
				powsum(n,x2)-powsum(n,x1-1)*theta_(x1-1);
		else;
          id  sum`i'(j`i',x1?,x2?)*sign`i'(j`i') = sign(x1)/2+sign(x2)/2;
          id  sum`i'(j`i',x1?,x2?) = x2+1-x1;
		endif;
      endif;
    endif;
  endif;
  endif;
  endrepeat;
endif;
id  den`i'(n?,x1?,x2?) = den`i'(x1,x2)^n;
id  den(N)*N = 1;
id	sign(x?number_) = sign_(x);
*
#endprocedure
*
*--#] summit : 
*--#[ sumnmi0 :
*
#procedure sumnmi0(i)
*
*   Procedure for sums sum(j,0,n)*S(R(?a),j)*S(R(?b),n-j) [*sign(j)]
*   This is the special case of sumnmii with k=0.
*
*	First rotate to the S with the smallest depth
*
if ( count(den`i',1) == 0 );
	id	sum`i'(j`i',0,n?)*S`i'(R(?a),0,j`i')*S`i'(R(?b),n?,-j`i') =
		S`i'(R(?a),n,j`i'-n)*S`i'(R(?b),0,n-j`i')*replace_(j`i',n-j`i')*theta_(nargs_(?a)-nargs_(?b)-1)*sum`i'(n-j`i',0,n)
		+S`i'(R(?a),0,j`i')*S`i'(R(?b),n,-j`i')*theta_(nargs_(?b)-nargs_(?a))*sum`i'(j`i',0,n);
	id	sum`i'(j`i',1,n?)*S`i'(R(?a),0,j`i')*S`i'(R(?b),n?,-j`i') =
		S`i'(R(?a),n,j`i'-n)*S`i'(R(?b),0,n-j`i')*replace_(j`i',n-j`i')*theta_(nargs_(?a)-nargs_(?b)-1)*sum`i'(n-j`i',0,n)
		+S`i'(R(?a),0,j`i')*S`i'(R(?b),n,-j`i')*theta_(nargs_(?b)-nargs_(?a))*sum`i'(j`i',0,n);
	SplitArg,sign`i';
	repeat id sign`i'(x1?,x2?,?a) = sign`i'(x1)*sign`i'(x2,?a);
	id	sign`i'(-j`i') = sign`i'(j`i');
	id	sign`i'(x?number_) = sign_(x);
	id	sign`i'(x?!{j`i'}) = sign(x);
endif;
repeat;
  if ( ( count(den`i',1) == 0 ) && ( match(S`i'(R(?a),0,j`i')*S`i'(R(?b),n?,-j`i')) ) );
    if ( count(sign`i',1) );
        id  sum`i'(j`i',0,n?)*sign`i'(j`i')*
                S`i'(R(?a),0,j`i')*S`i'(R(n2?,?b),n?,-j`i')*j`i'^x?pos0_ =
            sum`i'(j`i',1,n)*S`i'(R(?b),0,j`i')*den`i'(abs_(n2),0,j`i')
                *(theta_(n2)+theta_(-n2)*sign`i'(j`i'))*theta(n-1)
                *sum(j,1,n,-j`i')*S`i'(R(?a),0,j)
				*sign`i'(j)*j^x;
        id  sum`i'(j`i',1,n?)*sign`i'(j`i')*
                S`i'(R(n1?,?a),0,j`i')*S`i'(R(n2?,?b),n?,-j`i')*j`i'^x?pos0_ =
            sum`i'(j`i',1,n)*S`i'(R(?b),0,j`i')*den`i'(abs_(n2),0,j`i')
                *(theta_(n2)+theta_(-n2)*sign`i'(j`i'))
                *sum(j,1,n,-j`i')*S`i'(R(?a),0,j)
				*sign`i'(j)*j^x;
    else;
        id  sum`i'(j`i',0,n?)*S`i'(R(?a),0,j`i')
							 *S`i'(R(n2?,?b),n?,-j`i')*j`i'^x?pos0_ =
            sum`i'(j`i',1,n)*S`i'(R(?b),0,j`i')*den`i'(abs_(n2),0,j`i')
                *(theta_(n2)+theta_(-n2)*sign`i'(j`i'))*theta(n-1)
                *sum(j,1,n,-j`i')*S`i'(R(?a),0,j)*j^x;
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),0,j`i')
							 *S`i'(R(n2?,?b),n?,-j`i')*j`i'^x?pos0_ =
            sum`i'(j`i',1,n)*S`i'(R(?b),0,j`i')*den`i'(abs_(n2),0,j`i')
                *(theta_(n2)+theta_(-n2)*sign`i'(j`i'))
                *sum(j,1,n,-j`i')*S`i'(R(?a),0,j)*j^x;
    endif;
    repeat;
		if ( count(j,1) == 0 );
	        id  sum(j,1,x2?,-j`i')*S`i'(R(n1?,?a),0,j)*sign`i'(j) =
    	        sign(x2)*sign`i'(j`i')*S`i'(R(n1,?a),x2,-j`i')/2
        	    +S`i'(R(-n1,?a),x2,-j`i')/2;
	        id  sum(j,1,x2?,-j`i')*S`i'(R(n1?pos_,?a),0,j) =
    	        (x2-j`i'+1)*S`i'(R(n1,?a),x2,-j`i')
        	    -sum(j,1,x2,-j`i')*S`i'(R(?a),0,j)*delta_(n1-1)
            	-S`i'(R(n1-1,?a),x2,-j`i')*theta_(n1-2);
	        id  sum(j,1,x2?,-j`i')*S`i'(R(n1?neg_,?a),0,j) =
    	        (x2-j`i'+1)*S`i'(R(n1,?a),x2,-j`i')
        	    -sum(j,1,x2,-j`i')*S`i'(R(?a),0,j)*sign`i'(j)*delta_(n1+1)
            	-S`i'(R(n1+1,?a),x2,-j`i')*theta_(-n1-2);
		elseif ( count(j,1) > 0 );
			id	sum(j,x1?,x2?,x3?) = sum(j,x1,x2+x3);
			id	S1(R(?a),j) = S1(R(?a),0,j);
			#call sumposq(`i')
			repeat id  j`i'*den`i'(n?pos_,0,j`i') = den`i'(n-1,0,j`i');
			id	den`i'(0,0,j`i') = 1;
			if ( count(den`i',1) == 0 );
				id	sum`i'(j`i',0,n?)*S`i'(R(?a),0,j`i')*S`i'(R(?b),n?,-j`i') =
					S`i'(R(?a),n,j`i'-n)*S`i'(R(?b),0,n-j`i')*replace_(j`i',n-j`i')*theta_(nargs_(?a)-nargs_(?b)-1)*sum`i'(n-j`i',0,n)
					+S`i'(R(?a),0,j`i')*S`i'(R(?b),n,-j`i')*theta_(nargs_(?b)-nargs_(?a))*sum`i'(j`i',0,n);
				id	sum`i'(j`i',1,n?)*S`i'(R(?a),0,j`i')*S`i'(R(?b),n?,-j`i') =
					S`i'(R(?a),n,j`i'-n)*S`i'(R(?b),0,n-j`i')*replace_(j`i',n-j`i')*theta_(nargs_(?a)-nargs_(?b)-1)*sum`i'(n-j`i',0,n)
					+S`i'(R(?a),0,j`i')*S`i'(R(?b),n,-j`i')*theta_(nargs_(?b)-nargs_(?a))*sum`i'(j`i',0,n);
				SplitArg,sign`i';
				repeat id sign`i'(x1?,x2?,?a) = sign`i'(x1)*sign`i'(x2,?a);
				id	sign`i'(-j`i') = sign`i'(j`i');
				id	sign`i'(x?number_) = sign_(x);
				id	sign`i'(x?!{j`i'}) = sign(x);
			endif;
			id	theta(x?)*theta(x?) = theta(x);
		endif;
    endrepeat;
    if ( match(S`i'(R,0,j)) );
        id  S`i'(R,?a) = 1;
        id  sum(j,1,x2?,-j`i')*sign`i'(j) = -1/2+sign(x2)*sign`i'(j`i')/2;
        id  sum(j,1,x2?,-j`i') = x2-j`i';
    endif;
    id  S`i'(R,?a) = 1;
    id  sign`i'(j`i')*sign`i'(j`i') = 1;
    id  j`i'*den`i'(n?,0,j`i') = den`i'(n-1,0,j`i');
    id  den`i'(0,0,j`i') = 1;
endif;
endrepeat;
if ( match(S`i'(R(?a),x1?,-j`i')) );
    id  den`i'(x1?,j`i') = den`i'(1,x1,j`i');
    repeat id den`i'(n1?,x1?,j`i')*den`i'(n2?,x1?,j`i')
            = den`i'(n1+n2,x1,j`i');
    if ( count(den`i',1) == 1 );
        #call sumnmii(`i')
    endif;
endif;
id  sign(x?)*sign(x?) = 1;
#endprocedure
*
*--#] sumnmi0 : 
*--#[ sumnmic :
*
#procedure sumnmic(i)
*
*   Sums of the type
*   sum`i'(j`i',1,n-1)*sign`i'(j`i')*bino`i'(n,j`i')*
*           S`i'(R(?a),n-j`i')*S`i'(R(?b),j`i')/j`i'^k
*   with ?a, ?b all positive and k >= 0.
*   These are described in the second part of appendix C of the paper.
*
*   J.Vermaseren,31-oct-1997
*
id  S`i'(R,x1?,x2?) = TT(R,x1,x2);
#do ii = 1,`MAXWEIGHT'
    id  S`i'(R(<n1?pos_>,...,<n`ii'?pos_>),x1?,x2?) = TT(R(n1,...,n`ii'),x1,x2);
#enddo
if ( count(TT,1) == 2 );
    id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*
            TT(R(?a),n?,-j`i')*TT(R(?b),0,j`i')/j`i'^k?pos0_ =
                -SS(R(?a),R(?b),k,n);
    if ( count(j`i',1) == 0 )
        id  sum`i'(j`i',0,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*
                TT(R(?a),n?,-j`i')*TT(R(?b),0,j`i') =
                    -SS(R(?a),R(?b),0,n);
else if ( ( count(TT,1) == 1 ) && ( count(S`i',1) == 0 ) );
    id  sum`i'(j`i',1,n?)*sign`i'(j`i')*bino`i'(n?,0,j`i')*
            TT(R(?a),n?,-j`i')/j`i'^k?pos0_ = -SS(R(?a),R,k,n);
endif;
id  TT(?a) = S`i'(?a);
id  SS(?a) = acc1(SS(?a));
*
*   At this point we have in SS a sum we can do.
*
repeat;
  argument,acc1;
    id  SS(R(n1?,?a),R(?b),k?{2,...,`MAXWEIGHT'},n?) =
        +SS(R(n1,?a),R(?b),k-1,1,n)
        +sum_(jjj,1,k,SS(R(?a),R(?b),jjj,k+n1-jjj,n)*binom_(k+n1-1-jjj,n1-1))
        +sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(k+n1-jjj),n)*binom_(k+n1-1-jjj,k-1))
        -sum_(jjj,1,k-1,SS(R(?a),R(?b),jjj,k+n1-jjj,n)*binom_(k+n1-2-jjj,n1-1))
        -sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(k+n1-jjj),n)*binom_(k+n1-2-jjj,k-2));
    id  SS(R(n1?,?a),R(?b),1,n?) =
        +SS(R(n1,?a),R(?b),0,1,n)
        +SS(R(?a),R(?b),1,n1,n)
        +sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(n1+1-jjj),n))
        -SS(R(?b),R(?a),n1,-1,n);
    id  SS(R(n1?,?a),R(?b),k?{2,...,`MAXWEIGHT'},n2?,?c,n?) =
        +SS(R(n1,?a),R(?b),k-1,1,n2,?c,n)
        +sum_(jjj,1,k,SS(R(?a),R(?b),jjj,k+n1-jjj,n2,?c,n)*binom_(k+n1-1-jjj,n1-1))
        +sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(k+n1-jjj),n2,?c,n)*binom_(k+n1-1-jjj,k-1))
        -sum_(jjj,1,k-1,SS(R(?a),R(?b),jjj,k+n1-jjj,n2,?c,n)*binom_(k+n1-2-jjj,n1-1))
        -sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(k+n1-jjj),n2,?c,n)*binom_(k+n1-2-jjj,k-2));
    id  SS(R(n1?,?a),R(?b),1,n2?,?c,n?) =
        +SS(R(n1,?a),R(?b),0,1,n2,?c,n)
        +SS(R(?a),R(?b),1,n1,n2,?c,n)
        +sum_(jjj,1,n1,SS(R(?b),R(?a),jjj,-(1+n1-jjj),n2,?c,n))
        -SS(R(?b),R(?a),n1,-1,n2,?c,n);
    id  SS(R(n1?,?a),R(n2?,?b),0,n3?,?c,n?) =
        +SS(R(n1,?a),R(?b),n2-1,sig_(n3)+n3,?c,n)
        +SS(R(n2,?b),R(?a),n1-1,-n3-sig_(n3),?c,n);
    id  SS(R(n1?,?a),R(n2?,?b),0,n?) =
        +SS(R(n1,?a),R(?b),n2-1,n)*den(n)
        +SS(R(n2,?b),R(?a),n1-1,n)*sign(n)*den(n);
  endargument;
endrepeat;
id  acc1(x?) = x;
id  SS(R(n1?,?a),R,0,k?,?c,n?) = SS(R,R(n1,?a),0,-k,?c,n);
id  SS(R(n1?,?a),R,0,n?) = SS(R,R(n1,?a),0,n)*sign(n);
id  SS(R,R(?b),n1?,n2?,?a,n?) = Conj(R(?b)/nn^n1)*TT(n2,?a,n)
        +TT(R(?b),-n2-sig_(n2)*n1,?a,n);
id  SS(R,R(?b),n1?pos0_,n?) = Conj(R(?b)/nn^n1)*TT(n)
        +S(R(?b),n)*sign(n)*den(n)^n1;
#call conjug(nn,1)
id  R(?b)*TT(n2?,?a,n?)/nn^n1? = TT(R(?b),sig_(n2)*n1+n2,?a,n);
id  R(?b)*TT(n?)/nn^n1? = S(R(?b),n)*den(n)^n1;
id  TT(n2?int_,?a,n?)/nn^n1? = TT(R,sig_(n2)*n1+n2,?a,n);
id  TT(n?)/nn^n1? = den(n)^n1;
id  TT(R(?a),?b,n?) = S(R(reverse_(?b),?a),n);
id  sign(x?{N,j1,...,j`MAXWEIGHT'})*sign(x?{N,j1,...,j`MAXWEIGHT'}) = 1;
repeat id sign(n1?number_)*sign(n2?number_) = sign(n1+n2);
id  sign(x?int_) = sign_(x);
*
#endprocedure
*
*--#] sumnmic : 
*--#[ sumnmii :
*
#procedure sumnmii(i)
*
*   Sums objects of the type
*   sum`i'(j`i',1,n-1)*S`i'(R(?a),n-j`i')*S`i'(R(?b),j`i')/j`i'^k
*   for any (integer) values of ?a, ?b and k (k>0)
*
*   Does not do the case k=0.
*
*   J.Vermaseren,30-oct-1997
*
if ( count(j`i',1) < 0 );
    id  1/j`i'^n? = den`i'(n,0,j`i');
    repeat id den`i'(n1?,0,j`i')*den`i'(n2?,0,j`i') = den`i'(n1+n2,0,j`i');
endif;
if ( match(S`i'(R(?a),n?)) );
    SplitArg,(j`i'),S`i';
    id  S`i'(R(?a),j`i') = S`i'(R(?a),0,j`i');
    if ( match(sum`i'(j`i',n1?,n2?)*S`i'(R(?a),n2?,-j`i')) == 0 );
        id  sum`i'(j`i',n1?,n2?) = sum`i'(j`i',n1,n2+1);
        if ( match(sum`i'(j`i',n1?,n2?)*S`i'(R(?a),n2?,-j`i')) == 0 );
            id  sum`i'(j`i',n1?,n2?) = sum`i'(j`i',n1,n2-1);
        endif;
    endif;
endif;
if ( count(den`i',1) == 1 );
    if ( count(S`i',1) == 2 ); 
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),n?,-j`i')*S`i'(R(?b),0,j`i')
                        *sign`i'(j`i')*den`i'(k?,0,j`i') =
                            SS(R(?a),R(?b),-k,n);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),n?,-j`i')*S`i'(R(?b),0,j`i')
                        *den`i'(k?,0,j`i') = SS(R(?a),R(?b),k,n);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),x1?,-j`i')*S`i'(R(?b),0,j`i')
                        *sign`i'(j`i')*den`i'(k?,0,j`i') =
                            SS(R(?a),R(?b),-k,n+1,x1);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),x1?,-j`i')*S`i'(R(?b),0,j`i')
                        *den`i'(k?,0,j`i') = SS(R(?a),R(?b),k,n+1,x1);
    elseif ( count(S`i',1) == 1 );
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),n?,-j`i')
                        *sign`i'(j`i')*den`i'(k?,0,j`i') =
                            SS(R(?a),R,-k,n);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),n?,-j`i')
                        *den`i'(k?,0,j`i') = SS(R(?a),R,k,n);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),x1?,-j`i')
                        *sign`i'(j`i')*den`i'(k?,0,j`i') =
                            SS(R(?a),R,-k,n+1,x1);
        id  sum`i'(j`i',1,n?)*S`i'(R(?a),x1?,-j`i')
                        *den`i'(k?,0,j`i') = SS(R(?a),R,k,n+1,x1);
    endif;
    id  SS(?a,n?,n?) = SS(?a,n);
    id  SS(R(?a),R(?b),k?pos_,n?,x1?) = sum`i'(j`i',1,n-1)*
            S`i'(R(?a),x1,-j`i')*S`i'(R(?b),0,j`i')*den`i'(0,j`i')^k;
    id  SS(R(?a),R(?b),k?neg_,n?,x1?) = sum`i'(j`i',1,n-1)*sign`i'(j`i')*
            S`i'(R(?a),x1,-j`i')*S`i'(R(?b),0,j`i')*den`i'(0,j`i')^(abs_(k));
endif;
*
*   The sums that this routine can handle are now in the function SS.
*   Notation in the sequel: we add pairs of k,n if there are new denominators
*   and summations boundaries.
*   Eventually we hit on sums we can do and then we work backwards in a
*   combination of sums and synchronizations.
*
repeat id   SS(R(n1?,?a),R(?b),k?,?c) =
        +sum_(jjj,1,abs_(k),
            SS(R(?a),R(?b),sig_(n1*k)*jjj,sig_(n1)*(abs_(k)+abs_(n1)-jjj),?c)*
            binom_(abs_(k)+abs_(n1)-1-jjj,abs_(n1)-1))
        +sum_(jjj,1,abs_(n1),
            SS(R(?b),R(?a),sig_(n1*k)*jjj,sig_(k)*(abs_(k)+abs_(n1)-jjj),?c)*
            binom_(abs_(k)+abs_(n1)-1-jjj,abs_(k)-1));
id  SS(R,R(?a),k?,m?,?c,n?) = SS(R,R(k,?a),m,?c,n)
        -SS(R,R(?a),sig_(k)*m+sig_(m)*k,?c,n);
id  SS(R,R(?a),?c,n?) = S(R(reverse_(?c),?a),n);
#endprocedure
*
*--#] sumnmii :
*--#[ sumposp :
*
#procedure sumposp(j)
*
*   Sums positive (or zero) powers of j`j' possibly in combination
*   with one S`j' function and possibly a sign`j'
*
*   J.Vermaseren 7-jun-1998
*
repeat;
    if ( count(S`j',1) == 1 );
        if ( count(j`j',1) < 0 );
            id  sum`j'(j`j',1,x2?)*sign`j'(j`j')*S`j'(R(?a),0,j`j')/j`j'^m?
                            = S(R(-m,?a),x2);
            id  sum`j'(j`j',x1?,x2?)*sign`j'(j`j')*S`j'(R(?a),0,j`j')/j`j'^m?
                            = S(R(-m,?a),x2)-S(R(-m,?a),x1-1);
            id  sum`j'(j`j',1,x2?)*S`j'(R(?a),0,j`j')/j`j'^m?
                            = S(R(m,?a),x2);
            id  sum`j'(j`j',x1?,x2?)*S`j'(R(?a),0,j`j')/j`j'^m?
                            = S(R(m,?a),x2)-S(R(m,?a),x1-1);
        else;
            if ( count(sign`j',1) );
                id  sum`j'(j`j',x?{0,1},n?)*sign`j'(j`j')*
                                j`j'^m?pos0_*S`j'(R(n1?pos_,?a),0,j`j') =
                    S(R(n1,?a),n)*mpowsum(m,n)
                    -sum`j'(j`j',1,n)*S`j'(R(?a),0,j`j')*
                            mpowsum1(m,j`j')/j`j'^n1;
                id  sign_(j`j') = sign`j'(j`j');
                id  sum`j'(j`j',x?{0,1},n?)*sign`j'(j`j')*
                                j`j'^m?pos0_*S`j'(R(n1?neg_,?a),0,j`j') =
                    S(R(n1,?a),n)*mpowsum(m,n)
                        -sum`j'(j`j',1,n)*S`j'(R(?a),0,j`j')
                                *mpowsum1(m,j`j')*sign`j'(j`j')*j`j'^n1;
                id  sign_(j`j') = sign`j'(j`j');
                id  sign`j'(j`j')*sign`j'(j`j') = 1;
            else;
                id  sum`j'(j`j',x?{0,1},n?)*j`j'^m?pos0_*S`j'(R(n1?pos_,?a),0,j`j') =
                            S(R(n1,?a),n)*powsum(m,n)
                            -sum`j'(j`j',1,n)*S`j'(R(?a),0,j`j')*
                                    powsum1(m,j`j')/j`j'^n1;
                id  sum`j'(j`j',x?{0,1},n?)*j`j'^m?pos0_*S`j'(R(n1?neg_,?a),0,j`j') =
                            S(R(n1,?a),n)*powsum(m,n)
                            -sum`j'(j`j',1,n)*S`j'(R(?a),0,j`j')
                                *powsum1(m,j`j')*sign`j'(j`j')*j`j'^n1;
            endif;
        endif;
    elseif ( count(S`j',1) == 0 );
        if ( count(j`j',1) >= 0 );
            id  sum`j'(j`j',x?{0,1},x2?)*sign`j'(j`j')*j`j'^m? = mpowsum(m,x2);
            id  sum`j'(j`j',x1?,x2?)*sign`j'(j`j')*j`j'^m? =
                             mpowsum(m,x2)-mpowsum(m,x1-1);
            id  sum`j'(j`j',x?{0,1},x2?)*j`j'^m? = powsum(m,x2);
            id  sum`j'(j`j',x1?,x2?)*j`j'^m? = powsum(m,x2)-powsum(m,x1-1);
        else;
            id  sum`j'(j`j',1,x2?)*sign`j'(j`j')/j`j'^m? = S(R(-m),x2);
            id  sum`j'(j`j',x1?,x2?)*sign`j'(j`j')/j`j'^m? =
                             S(R(-m),x2)-S(R(-m),x1-1);
            id  sum`j'(j`j',1,x2?)/j`j'^m? = S(R(m),x2);
            id  sum`j'(j`j',x1?,x2?)/j`j'^m? = S(R(m),x2)-S(R(m),x1-1);
        endif;
    endif;
    id  S`j'(R,?a) = 1;
    id  S(R,?a) = 1;
endrepeat;
#endprocedure
*
*--#] sumposp : 
*--#[ sumposq :
*
#procedure sumposq(j)
*
*   Sums positive (or zero) powers of j`j' possibly in combination
*   with one S`j' function and possibly a sign`j'
*
*   J.Vermaseren 7-jun-1998
*
repeat;
    if ( match(S`j'(R(?a),0,j)) == 1 );
        if ( count(j,1) < 0 );
            id  sum(j,1,x2?)*sign`j'(j)*S`j'(R(?a),0,j)/j^m?
                            = S`j'(R(-m,?a),x2);
            id  sum(j,x1?,x2?)*sign`j'(j)*S`j'(R(?a),0,j)/j^m?
                            = S`j'(R(-m,?a),x2)-S`j'(R(-m,?a),x1-1);
            id  sum(j,1,x2?)*S`j'(R(?a),0,j)/j^m?
                            = S`j'(R(m,?a),x2);
            id  sum(j,x1?,x2?)*S`j'(R(?a),0,j)/j^m?
                            = S`j'(R(m,?a),x2)-S`j'(R(m,?a),x1-1);
        else;
            if ( count(sign`j',1) );
                id  sum(j,x?{0,1},n?)*sign`j'(j)*
                                j^m?pos0_*S`j'(R(n1?pos_,?a),0,j) =
                    S`j'(R(n1,?a),n)*mpowsum(m,n)
                    -sum(j,1,n)*S`j'(R(?a),0,j)*
                            mpowsum1(m,j)/j^n1;
                id  sign_(j) = sign`j'(j);
                id  sum(j,x?{0,1},n?)*sign`j'(j)*
                                j^m?pos0_*S`j'(R(n1?neg_,?a),0,j) =
                    S`j'(R(n1,?a),n)*mpowsum(m,n)
                        -sum(j,1,n)*S`j'(R(?a),0,j)
                                *mpowsum1(m,j)*sign`j'(j)*j^n1;
                id  sign_(j) = sign`j'(j);
                id  sign`j'(j)*sign`j'(j) = 1;
            else;
                id  sum(j,x?{0,1},n?)*j^m?pos0_*S`j'(R(n1?pos_,?a),0,j) =
                            S`j'(R(n1,?a),n)*powsum(m,n)
                            -sum(j,1,n)*S`j'(R(?a),0,j)*
                                    powsum1(m,j)/j^n1;
                id  sum(j,x?{0,1},n?)*j^m?pos0_*S`j'(R(n1?neg_,?a),0,j) =
                            S`j'(R(n1,?a),n)*powsum(m,n)
                            -sum(j,1,n)*S`j'(R(?a),0,j)
                                *powsum1(m,j)*sign`j'(j)*j^n1;
            endif;
        endif;
    elseif ( match(S`j'(R(?a),0,j)) == 0 );
        if ( count(j,1) >= 0 );
            id  sum(j,x?{0,1},x2?)*sign`j'(j)*j^m? = mpowsum(m,x2);
            id  sum(j,x1?,x2?)*sign`j'(j)*j^m? =
                             mpowsum(m,x2)-mpowsum(m,x1-1);
            id  sum(j,x?{0,1},x2?)*j^m? = powsum(m,x2);
            id  sum(j,x1?,x2?)*j^m? = powsum(m,x2)-powsum(m,x1-1);
        else;
            id  sum(j,1,x2?)*sign`j'(j)/j^m? = S`j'(R(-m),x2);
            id  sum(j,x1?,x2?)*sign`j'(j)/j^m? =
                             S`j'(R(-m),x2)-S`j'(R(-m),x1-1);
            id  sum(j,1,x2?)/j^m? = S`j'(R(m),x2);
            id  sum(j,x1?,x2?)/j^m? = S`j'(R(m),x2)-S`j'(R(m),x1-1);
        endif;
    endif;
    id  S`j'(R,?a) = 1;
	id	sign_(x?) = sign(x);
	SplitArg,sign;
	repeat id sign(x1?,x2?,?a) = sign(x1)*sign(x2,?a);
	id	sign(j`i') = sign`i'(j`i');
	id	sign(-j`i') = sign`i'(j`i');
	id	sign(x?)*sign(x?) = 1;
	id	sign(x?number_) = sign_(x);
endrepeat;
id	S`j'(R(?a),x1?,x2?) = S`j'(R(?a),x1+x2);
SplitArg,((j`j')),S`j';
id	S`j'(R(?a),j`j') = S`j'(R(?a),0,j`j');
id	S`j'(R(?a),j) = S`j'(R(?a),0,j);
#endprocedure
*
*--#] sumposq : 
*--#[ sumreg :
*
#procedure sumreg(j)
*
*   Final regularization of a sum.
*
if ( count(bino`j',1) == 0 );
    id  sum`j'(j`j',x1?,x2?)*den`j'(x3?,-j`j') =
            X(x3-x2)*sum`j'(j`j',x1,x2)*den`j'(x3,-j`j');
    if ( count(X,1) );
            #call flipj(`j')
            id  X(x1?) = 1;
            #call synchds(`j')
    endif;
    #call dosign
*elseif ( ( count(S`j',1,den`j',1) == 1 )
*		 && match(sum`j'(j`j',n1?,n?)*S`j'(R(?a),n?,-j`j')) );
*    #call flipj(`j')
*    #call synchds(`j')
endif;
.sort:sumreg-flip direction;
if ( match(den`j'(x1?!{0,0},j`j')) );
    id,once,den`j'(x1?,j`j') = den`j'(x1,j`j')*X(x1);
    #call movej(`j',X)
endif;
id  X(x1?) = 1;
#call dosign
.sort:sumreg den`j' shift;
id  sum`j'(j`j',x1?,x2?)*den`j'(x3?,-j`j') =
        X(x3-x2)*sum`j'(j`j',x1,x2)*den`j'(x3,-j`j');
if ( count(X,1) );
        #call flipj(`j')
endif;
id  X(x1?) = 1;
#call dosign
.sort:sumreg-flip direction;
if ( count(bino`j',1) == 0 );
    if ( match(den`j'(x1?!{0,0},j`j')) );
        id,once,den`j'(x1?,j`j') = den`j'(x1,j`j')*X(x1);
        #call movej(`j',X)
        id  X(x1?) = 1;
    endif;
    #call dosign
endif;
.sort:sumreg den`j' shift;
id  sum`j'(j`j',n1?,n2?) = sum`j'(j`j',n1,n2)*theta_(n2-n1);
id  theta_(x?) = theta(x);
#do ni = `j'-1,1,-1
#call theta(`ni')
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#enddo
#call theta(N)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
repeat;
    id  sum`j'(j`j',0,n?pos_) = sum`j'(j`j',0,n-1)+replace_(j`j',n);
endrepeat;
id  sum`j'(j`j',0,0) = replace_(j`j',0);
id  sum`j'(j`j',0,n?neg_) = 0;

if ( match(den`j'(0,j`j')) );
    id  sum`j'(j`j',n1?pos_,n2?) =
            sum`j'(j`j',1,n2) - sum_(jjj,1,n1-1,su(jjj));
endif;
id  sum_(jjj,x1?,x2?,su(jjj)) = f1(x1,x2,x2-x1)*su(jjj);
repeat id f1(x1?,x2?,x3?pos_) = f1(x1,x2-1,x3-1)+replace_(jjj,x2);
id  f1(x1?,x2?,0) = replace_(jjj,x2);
id  f1(x1?,x2?,x3?neg_) = 0;
id  f1(x1?,x2?,x3?)*su(jjj) = sum_(jjj,x1,x2,su(jjj));
*
*   In case some sum has now been eliminated we replace the relevant
*   objects by their new values.
*
if ( count(su,1) );
    id  su(n?) = replace_(j`j',n);
    id  S`j'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
    id  bino`j'(n1?,n2?,n3?) = fac(n1)*invfac(n2+n3)*invfac(n1-n2-n3);
    id  den`j'(x1?,x2?) = den(x1+x2);
    id  fac`j'(x1?,x2?) = fac(x1+x2);
    id  invfac`j'(x1?,x2?) = invfac(x1+x2);
    id  sign`j'(x?) = sign_(x);
    id  fac(x?int_) = fac_(x);
    id  invfac(x?int_) = invfac_(x);
*
*   The next replacement looks dumb, but it protects again divisions
*   by zero which might be cancelled out in the sort or survive when
*   there are errors in what we are trying to do. It would be better
*   if they survive as some kind of indicator of problems.
*
    id  den(x?pos_) = 1/x;
    id  den(x?neg_) = 1/x;
    #call subesses(S)
endif;
*
*   The final introduction of binomial coefficients.
*   After this we should not change anything.
*
if ( count(fac`j',1,invfac`j',1) >= 2 );
    id  invfac`j'(n1?,j`j')*invfac`j'(n2?,-j`j') =
            bino`j'(n1+n2,n1,j`j')*invfac(n1+n2);
    id  fac`j'(n1?,j`j')*invfac`j'(n2?,j`j') =
            bino`j'(n1,j`j',n2,j`j')*fac(n1-n2);
endif;
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#endprocedure
*
*--#] sumreg :
*--#[ sumspec :
*
#procedure sumspec(i)
*
*   Some special sums.
*   This deals with a number of sums that can only be handled
*   for specific cases. If the program comes here and the sum
*   cannot be done in this routine, we are out of luck!
*
if ( ( count(S`i',1,den`i',1) == 0 ) && ( count(j`i',1) == 0 ) );
    id  sum`i'(j`i',0,n1?)*fac`i'(0,j`i')*fac`i'(n2?,-j`i')*sign`i'(j`i') =
            fac(n2+1)*den(n2+2)+sign(n1)*fac(n1+1)*fac(n2-n1)*den(n2+2);
    id  sum`i'(j`i',n3?,n1?)*fac`i'(0,j`i')*fac`i'(n2?,-j`i')*sign`i'(j`i') =
            +sign(n1)*fac(n1+1)*fac(n2-n1)*den(n2+2)
            +sign(n3)*fac(n3)*fac(n2-n3+1)*den(n2+2);
    id  sum`i'(j`i',0,n?)*fac`i'(m?,j`i')*invfac`i'(0,j`i') =
            fac(n+m+1)*invfac(n)*den(m+1);
    id  sum`i'(j`i',0,n?)*fac`i'(m?,j`i')*invfac`i'(n1?,j`i') =
            fac(n+m+1)*invfac(n+n1)*den(m+1-n1)*theta(m-n1)
            -fac(m)*invfac(n1-1)*den(m+1-n1)*theta(m-n1)*theta(n1-1);
elseif ( ( count(S`i',1,den`i',1) == 1 ) && ( count(j`i',1) == 0 ) );
    id  sum`i'(j`i',n3?,n1?)*fac`i'(0,j`i')*fac`i'(n2?,-j`i')
            *sign`i'(j`i')*S`i'(R(1),0,j`i') =
                    +sign(n1)*fac(n1+1)*fac(n2-n1)*
                            (S(R(1),n1+1)-den(n2+2))*den(n2+2)
                    +sign(n3)*fac(n3)*fac(n2-n3+1)*
                            (S(R(1),n3)-den(n2+2))*den(n2+2);
    id  sum`i'(j`i',n3?pos_,n1?)*fac`i'(0,j`i')*fac`i'(n2?,-j`i')
            *sign`i'(j`i')*den`i'(0,j`i') =
                    +sign(n1)*fac(n1)*fac(n2-n1)*den(n2+1)
                    +sign(n3)*fac(n3-1)*fac(n2-n3+1)*den(n2+1);
    id  sum`i'(j`i',0,n?)*den(n1?,-j`i') = X(n,n1,n1-n);
    id  X(n?,n1?,1)*fac`i'(m?,j`i')*invfac`i'(0,j`i') =
                    fac(n1+m)*invfac(n1)*(S(R(1),n1+m)-S(R(1),m));
    id  X(n?,n1?,n2?) = sum`i'(j`i',0,n)*den`i'(n1,-j`i');
    id  sum`i'(j`i',0,n?)*S`i'(R(1),n1?,-j`i') = X(n,n1,n1-n);
    id  X(n?,n1?,n2?{0,1})*fac`i'(m?,j`i')*invfac`i'(0,j`i') =
                    fac(n+m+2)*invfac(n1)*den(m+1)*(S(R(1),n+m+2)-S(R(1),m+1));
    id  X(n?,n1?,n2?) = sum`i'(j`i',0,n)*S`i'(R(1),n1,-j`i');
    id  sum`i'(j`i',0,n?)*fac`i'(m?,j`i')*invfac`i'(0,j`i')*S`i'(R(1),m?,j`i') =
                    +fac(n+m+1)*invfac(n)*den(m+1)*(S(R(1),n+m+1)-den(m+1));
    id  sum`i'(j`i',0,n?)*fac`i'(m?,j`i')*invfac`i'(0,j`i')*S`i'(R(2),m?,j`i') =
                    +fac(n+m+1)*invfac(n)*den(m+1)*S(R(2),n+m)
                    -sign(m)*fac(m)*den(m+1)*S(R(1),n+m)
                    -sign(m)*fac(m)*den(m+1)*A(1,m,n);
elseif ( ( count(S`i',1,den`i',1) == 2 ) && ( count(j`i',1) == 0 ) );
    id  sum`i'(j`i',n3?pos_,n1?)*fac`i'(0,j`i')*fac`i'(n1?,-j`i')
            *sign`i'(j`i')*den`i'(0,j`i')*den`i'(0,j`i') =
                    fac(n1)*(S(R(2),n1)+2*S(R(-2),n1))
                    -sum_(j,1,n3-1,fac_(j)*fac(n1-j)*sign_(j)/j^2);
    id  sum`i'(j`i',n3?pos_,n2?)*fac`i'(0,j`i')*fac`i'(n1?,-j`i')
            *sign`i'(j`i')*den`i'(0,j`i')*den`i'(0,j`i') = X(n1,n2,n3,n1-n2);
    id  X(n1?,n2?,n3?,n4?pos_) =
            fac(n1)*(S(R(2),n1)+2*S(R(-2),n1))
            -sum_(j,1,n3-1,fac_(j)*fac(n1-j)*sign_(j)/j^2)
            -sum(j,n2+1,n1,n1-n2-1)*fac(j)*fac_(n1-j)*sign(j)*den(j)*den(j);
    id  X(n1?,n2?,n3?,n4?) = sum`i'(j`i',n3,n2)*fac`i'(0,j`i')
            *fac`i'(n1,-j`i')*sign(j`i')*den`i'(0,j`i')*den`i'(0,j`i');
    repeat id sum(j,n1?,n2?,n3?pos0_) = sum(j,n1,n2-1,n3-1)+replace_(j,n2);
    id  sum(j,n1?,n2?,n3?neg_) = 0;
    id  sum`i'(j`i',0,n?)*fac`i'(m?,j`i')*invfac`i'(0,j`i')
            *S`i'(R(1),m?,j`i')*S`i'(R(1),m?,j`i') =
                    fac(n+m+1)*invfac(n)*den(m+1)*(den(m+1)*den(m+1)
                        +(S(R(1),n+m+1)-den(m+1))^2)
                    -fac(n+m)*invfac(n)*den(m+1)*den(n+m+1)
                    -sign(m)*fac(m)*den(m+1)*(S(R(1),n+m)+A(1,m,n));
    id  sum`i'(j`i',0,n?)*den(n1?,-j`i') = X(n,n1,n1-n);
    id  X(n?,n1?,1)*fac`i'(m?,j`i')*invfac`i'(0,j`i')*S`i'(R(1),m?,j`i') =
            fac(n+m)*invfac(n)*(S(R(1),n+m)^2-S(R(2),m+n)
                                +S(R(2),m)-S(R(1),m+n)*S(R(1),m));
    id  X(n?,n1?,n2?) = sum`i'(j`i',0,n)*den`i'(n1,-j`i');
    id  sum`i'(j`i',0,n?)*S`i'(R(1),n1?,-j`i') = X(n,n1,n1-n);
    id  X(n?,n1?,n2?{0,1})*fac`i'(m?,j`i')*invfac`i'(0,j`i')
            *S`i'(R(1),m?,j`i') =
                    fac(n+m+1)*invfac(n)*den(m+1)*(-S(R(2),n+m+1)+S(R(2),m+1)
                    +(S(R(1),n+m+1)-S(R(1),m+1))*(S(R(1),n+m+1)-den(m+1)));
    id  X(n?,n1?,n2?) = sum`i'(j`i',0,n)*S`i'(R(1),n1,-j`i');
endif;
#endprocedure
*
*--#] sumspec : 
*--#[ synch :
*
#procedure synch(i)
*
*   Procedure to synchronize the arguments of den,fac,invfac,bino,S.
*
*   Start with synchronizing products of S functions.
*   Note that if two S functions have been synchronized they are
*   brought to the basis. Hence only one will be left.
*
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
#call synchss(`i')
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
id  Even(N)*sign(N) = Even(N);
id  Odd(N)*sign(N) = -Odd(N);
#if `i' == 0
#call normden(0)
#else
#do ii = `i',1,-1
#call normden(`ii')
#enddo
#endif
.sort:Synchronize S;
#if `i' == 0
 #call densplit(0)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#else
 #do ii = `i',1,-1
  #call densplit(`ii')
 #enddo
#endif
#call densplit(N)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
.sort:synch-densplit-1;
#if `i' == 0
 #call theta(0)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#else
 #do ii = `i',1,-1
  #call theta(`ii')
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
 #enddo
#endif
#call theta(N)
.sort:synch-theta-1;
*
*   First see whether we need to invert the direction of summation
*
id  sum`i'(j`i',x1?,x2?)*den`i'(x3?,-j`i') =
        X(x3-x2)*sum`i'(j`i',x1,x2)*den`i'(x3,-j`i');
if ( match(X(x1?int_)) );
    #call flipj(`i')
endif;
id  X(x1?) = 1;
.sort:synch-flip direction;
*
*   Then see whether we need to move the summation a bit.
*
if ( match(den`i'(x1?pos_,j`i')) );
    id,once,den`i'(x1?pos_,j`i') = den`i'(x1,j`i')*X(x1);
    #call movej(`i',X)
    id  X(x1?) = 1;
endif;
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
.sort:synch den`i' shift;
*
*   Now comes the great recursion
*
#do k1 = 1,1
#do k2 = 1,1
*
*   Now we look at
*   1: combinations of den and S.
*
#call synchds(`i')
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
*
.sort:synch den`i',S`i';
*
*   2: combinations of den and fac,invfac.
*
#call synchdf(`i')
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
*
*   If there was action we have to restart with den and S.
*
if ( $syndf > 0 ) redefine k2 "0";
*
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
.sort:synch den`i',fac`i';
#enddo
*
*	Combination of j and fac or invfac
*	If there is a j there is no den!
*
if ( count(j`i',1) > 0 );
	repeat id j`i'*invfac`i'(n?pos_,j`i') =
				invfac`i'(n-1,j`i')-n*invfac`i'(n,j`i');
endif;
*
*   3: combinations of fac,invfac.and S
*
#call synchfs(`i')
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
*
*   If there was action, we have to start from the beginning again.
*
if ( $synfs > 0 ) redefine k1 "0";
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
*
.sort:synch fac`i',S`i';
#if `$synfs' > 0
#if `i' == 0
#call densplit(0)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#else
#do ii = `i',1,-1
#call densplit(`ii')
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#enddo
#endif
#call densplit(N)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
.sort:synch-densplit-2;
#if `i' == 0
#call theta(0)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#else
#do ii = `i',1,-1
#call theta(`ii')
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
#enddo
#endif
#call theta(N)
#ifdef `EXTRASUMMER'
; `EXTRASUMMER'
#endif
.sort:synch-theta-2;
#endif
id  S(R,?a) = 1;
id  S`i'(R,?a) = 1;
id  sum`i'(j`i',x1?,x2?)*den`i'(x3?,-j`i') =
        X(x3-x2)*sum`i'(j`i',x1,x2)*den`i'(x3,-j`i');
if ( match(X(x1?int_)) );
    #call flipj(`i')
else if ( ( count(den`i',1) == 0 ) && ( count(S`i',1) == 1 ) );
    id  sum`i'(j`i',x1?,x2?)*S`i'(?a,x3?,-j`i') =
            X(x3-x2)*sum`i'(j`i',x1,x2)*S`i'(?a,x3,-j`i');
    if ( match(X(x1?int_)) );
        #call flipj(`i')
    endif;
endif;
id  X(x1?) = 1;
#call synchds(`i')
id  sum`i'(j`i',n1?,n2?) = X(n1,n2,n2-n1);
if ( match(X(n1?,n2?,n3?int_)) );
    id X(n1?,n2?,n3?neg_) = 0;
    repeat;
        id  X(n1?,n2?,n3?pos_) = replace_(j`i',n2)+X(n1,n2-1,n3-1);
    endrepeat;
    id  X(n1?,n2?,0) = replace_(j`i',n2);
    id  S`i'(R(?a),n1?,n2?) = S(R(?a),n1+n2);
    id  bino`i'(n1?,n2?,n3?) = fac_(n1)*invfac_(n2+n3)*invfac_(n1-n2-n3);
    id  fac`i'(n1?,n2?) = fac_(n1+n2);
    id  invfac`i'(n1?,n2?) = invfac_(n1+n2);
    id  sign`i'(n1?) = sign_(n1);
    id  den`i'(n1?,n2?) = den(n1+n2);
    id  fac_(x?) = fac(x);
    id  invfac_(x?) = invfac(x);
    id  sign_(x?) = sign(x);
else;
    id  X(n1?,n2?,n3?) = sum`i'(j`i',n1,n2);
endif;
.sort:synch-flip direction;
 
#enddo
*
*   4: synchronize with the summation boundaries
*      also introduces the binomial coefficients
*
#call adjustsm(`i')
#call dosign
id  Even(N)*sign(N) = Even(N);
id  Odd(N)*sign(N) = -Odd(N);
id  sign(j`i') = sign`i'(j`i');
id  sign(-j`i') = sign`i'(j`i');
id  sign`i'(j`i')*sign`i'(j`i') = 1;
*
#endprocedure
*
*--#] synch : 
*--#[ synchdf :
*
#procedure synchdf(i)
*
*   Synchronizes combinations of factorials and denominators
*   den and fac and invfac.
*   Note: if there is a fac with which den can synchronize,
*   there cannot be an invfac et vise versa.
*   The variable $syndf will be 1 if anything relevant happened.
*
#$syndf = 0;
repeat;
    id,once,den`i'(x1?,x?)*fac`i'(x2?,x?) = f1(1,x1,x2,x,x2-x1);
    if ( match(f1(1,x1?,x2?,x3?,n?int_)) );
        repeat id f1(n1?,x1?,x2?,x?,x3?)*den`i'(x1?,x?) = f1(n1+1,x1,x2,x,x3);
        id  f1(?a) = f2(?a);
    else;
        id  f1(1,x1?,x2?,x?,x3?) = den`i'(x1,x)*f3(x2,x);
    endif;
endrepeat;
id  f3(?a) = fac`i'(?a);
repeat;
    id,once,den`i'(x1?,x?)*invfac`i'(x2?,x?) = f1(1,x1,x2,x,x2-x1);
    if ( match(f1(1,x1?,x2?,x3?,n?int_)) );
        repeat id f1(n1?,x1?,x2?,x?,x3?)*den`i'(x1?,x?) = f1(n1+1,x1,x2,x,x3);
        id  f1(?a) = f4(?a);
    else;
        id  f1(1,x1?,x2?,x?,x3?) = den`i'(x1,x)*f3(x2,x);
    endif;
endrepeat;
id  f3(?a) = invfac`i'(?a);
if ( match(f2(1,x1?,x2?,x?,0)) );
    id  f2(1,x1?,x2?,x?,0) = fac`i'(x2-1,x);
    $syndf = 1;
endif;
id  f2(n?,x1?,x2?,x?,0) = den`i'(x1,x)^n*fac`i'(x2,x);
id  f4(n?,x1?,x2?,x?,0) = den`i'(x1,x)^n*invfac`i'(x2,x);
*
*   f2 contains a combination of den and fac
*   f4 contains a combination of den and invfac
*
if ( count(f2,1,f4,1) );
    $syndf = 1;
#if `i' == 0
    Print "sych0: %t";
#endif
endif;

repeat;
    id  f2(n?pos_,x1?,x2?,x?,n1?pos_) =
            f2(n-1,x1,x2-1,x,n1-1) + n1*f2(n,x1,x2-1,x,n1-1);
    id  f2(1,x1?,x2?,x?,0) = fac`i'(x2-1,x);
    id  f2(n?,x1?,x2?,x?,0) = den`i'(x1,x)^n*fac`i'(x2,x);
    id  f2(0,x1?,x2?,x?,n1?) = fac`i'(x2,x);
endrepeat;
repeat;
    id  f2(n?,x1?,x2?,x?,-1) = fac`i'(x1,x)*den`i'(x1,x)^(n+1);
    id  f2(n?pos_,x1?,x2?,x?,n1?neg_) = fac`i'(x2,x)/(-n1-1)^n
            -sum_(jjj,1,n,f2(jjj,x1,x2+1,x,n1+1)/(-n1-1)^(n+1-jjj));
endrepeat;
repeat;
    id  f4(n?,x1?,x2?,x?,-1) = invfac`i'(x1,x)*den`i'(x1,x)^(n-1);
    id  f4(n?pos_,x1?,x2?,x?,n1?neg_) =
            f4(n-1,x1,x2+1,x,n1+1) + acc1(n1+1)*f4(n,x1,x2+1,x,n1+1);
	id	acc1(n?) = n;
    id  f4(0,x1?,x2?,x?,n1?) = invfac`i'(x2,x);
endrepeat;
repeat;
    id  f4(n?,x1?,x2?,x?,0) = den`i'(x1,x)^n*invfac`i'(x2,x);
    id  f4(n?pos_,x1?,x2?,x?,n1?pos_) = invfac`i'(x2,x)/n1^n*sign_(n)
            +sum_(jjj,1,n,f4(jjj,x1,x2-1,x,n1-1)/n1^(n+1-jjj)*sign_(n-jjj));
endrepeat;
*
#endprocedure
*
*--#] synchdf : 
*--#[ synchds :
*
#procedure synchds(i)
*
*   Procedure synchronizes products of den and S.
*   The algorithm is in the paper
*
repeat;
    if ( count(SS,1) == 0 );
        id,once,S`i'(?a,x1?!{x2?},j`i')*den`i'(x2?!{x1?},j`i') =
            SS(?a,x1,x2,x1-x2,1);
        if ( match(SS(?a,n?int_,1)) == 0 );
            id  SS(?a,x1?,x2?,x3?,1) = X(?a,x1,j`i')*den`i'(x2,j`i');
        endif;
    endif;
endrepeat;
id  X(?a) = S`i'(?a);
if ( match(SS(?a,n?int_,1)) );
    repeat id SS(?a,x2?,x3?,n?)*den`i'(x2?,j`i') = SS(?a,x2,x3,n+1);
    repeat;
        repeat;
        id  SS(R(n1?pos_,?a),x1?,x2?,-1,n2?) =
            +S`i'(R(n1,?a),x2,j`i')*(den`i'(x2,j`i'))^n2
            -S`i'(R(?a),x2,j`i')*(den`i'(x2,j`i'))^n1*(den`i'(x2,j`i'))^n2;
        id  SS(R(n1?neg_,?a),x1?,x2?,-1,n2?) =
            +S`i'(R(n1,?a),x2,j`i')*(den`i'(x2,j`i'))^n2
            -sign(x2)*sign`i'(j`i')*S`i'(R(?a),x2,j`i')*
                            (den`i'(x2,j`i'))^(-n1)*(den`i'(x2,j`i'))^n2;
        id  SS(R(?a),x1?,x2?,0,n2?) = S`i'(R(?a),x1,j`i')*(den`i'(x2,j`i'))^n2;
        id  SS(R,x1?,x2?,x3?,n1?) = (den`i'(x2,j`i'))^n1;
        id  SS(R(n1?pos_,?a),x1?,x2?,x3?pos_,n2?) =
            +SS(R(n1,?a),x1-1,x2,x3-1,n2)
            +sum_(jjj,1,n2,sign_(n2-jjj)*binom_(n1+n2-1-jjj,n1-1)
                    /x3^(n1+n2-jjj)*SS(R(?a),x1,x2,x3,jjj))
            +sum_(jjj,1,n1,sign_(n2)*binom_(n1+n2-1-jjj,n2-1)
                    /x3^(n1+n2-jjj)*(den`i'(x1,j`i'))^jjj*S`i'(R(?a),x1,j`i'));
        id  SS(R(n1?pos_,?a),x1?,x2?,x3?neg_,n2?) =
            +SS(R(n1,?a),x1+1,x2,x3+1,n2)
            -sum_(jjj,1,n2,sign_(n2-jjj)*binom_(n1+n2-1-jjj,n1-1)
                    /(x3+1)^(n1+n2-jjj)*SS(R(?a),x1+1,x2,x3+1,jjj))
            -sum_(jjj,1,n1,sign_(n2)*binom_(n1+n2-1-jjj,n2-1)
                    /(x3+1)^(n1+n2-jjj)*(den`i'(x1+1,j`i'))^jjj*S`i'(R(?a),x1+1,j`i'));
        endrepeat;
    id  SS(R(n1?neg_,?a),x1?,x2?,x3?pos_,n2?) =
            +SS(R(n1,?a),x1-1,x2,x3-1,n2)
            +sign(x1)*sign`i'(j`i')*sum_(jjj,1,n2,sign_(n2-jjj)*
                binom_(-n1+n2-1-jjj,-n1-1)
                    /x3^(-n1+n2-jjj)*SS(R(?a),x1,x2,x3,jjj))
            +sign(x1)*sign`i'(j`i')*sum_(jjj,1,-n1,sign_(n2)*
                    binom_(-n1+n2-1-jjj,n2-1)/x3^(-n1+n2-jjj)*
                        (den`i'(x1,j`i'))^jjj*S`i'(R(?a),x1,j`i'));
    id  SS(R(n1?neg_,?a),x1?,x2?,x3?neg_,n2?) =
            +SS(R(n1,?a),x1+1,x2,x3+1,n2)
            -sign(x1+1)*sign`i'(j`i')*sum_(jjj,1,n2,sign_(n2-jjj)*
                    binom_(-n1+n2-1-jjj,-n1-1)
                    /(x3+1)^(-n1+n2-jjj)*SS(R(?a),x1+1,x2,x3+1,jjj))
            -sign(x1+1)*sign`i'(j`i')*sum_(jjj,1,-n1,sign_(n2)*
                    binom_(-n1+n2-1-jjj,n2-1)
                    /(x3+1)^(-n1+n2-jjj)*(den`i'(x1+1,j`i'))^jjj*S`i'(R(?a),x1+1,j`i'));
    endrepeat;
    id  S`i'(R,n?,j`i') = 1;
endif;
*
#endprocedure
*
*--#] synchds : 
*--#[ synchfs :
*
#procedure synchfs(i)
*
*   Combinations of fac and S or invfac and S.
*   The variable $synfs will be 1 if anything relevant happened.
*
#$synfs = 0;
repeat;
    id,once,S`i'(R(?a),x1?,x?)*fac`i'(x2?,x?) = f1(R(?a),x1,x2,x,x2-x1);
    if ( match(f1(?a,n?int_)) );
        id  f1(?a) = f2(?a);
    else;
        id  f1(R(?a),x1?,x2?,x?,x3?) = S`i'(R(?a),x1,x)*f3(x2,x);
    endif;
endrepeat;
id  f3(?a) = fac`i'(?a);
repeat;
    id,once,S`i'(R(?a),x1?,x?)*invfac`i'(x2?,x?) = f1(R(?a),x1,x2,x,x2-x1);
    if ( match(f1(?a,n?int_)) );
        id  f1(?a) = f4(?a);
    else;
        id  f1(R(?a),x1?,x2?,x?,x3?) = S`i'(R(?a),x1,x)*f3(x2,x);
    endif;
endrepeat;
id  f3(?a) = invfac`i'(?a);
id  f2(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*fac`i'(x2,x);
id  f4(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*invfac`i'(x2,x);
if ( count(f2,1,f4,1) ) $synfs = 1;
repeat;
    id  f4(R(n1?,?a),x1?,x2?,x?,n?neg_) = f4(R(n1,?a),x1-1,x2,x,n+1)
            +S`i'(R(?a),x1,x)*invfac`i'(x2,x)*den`i'(x1,x)^(abs_(n1))
                *sign(x1)^theta_(-n1)*sign`i'(x)^theta_(-n1);
endrepeat;
repeat;
    id  f4(R(n1?,?a),x1?,x2?,x?,n?pos_) = f4(R(n1,?a),x1+1,x2,x,n-1)
            -S`i'(R(?a),x1+1,x)*invfac`i'(x2,x)*den`i'(x1+1,x)^(abs_(n1))
                *sign(x1)^theta_(-n1)*sign`i'(x)^theta_(-n1);
endrepeat;
*
*	Theta constraint from Sven
*
id  f4(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*invfac`i'(x2,x)*theta_(x1+x-1);
*id  f4(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*invfac`i'(x2,x);
repeat;
    id  f2(R(n1?,?a),x1?,x2?,x?,n?neg_) = f2(R(n1,?a),x1-1,x2,x,n+1)
            +S`i'(R(?a),x1,x)*fac`i'(x2,x)*den`i'(x1,x)^(abs_(n1))
                *sign(x1)^theta_(-n1)*sign`i'(x)^theta_(-n1);
endrepeat;
repeat;
    id  f2(R(n1?,?a),x1?,x2?,x?,n?pos_) = f2(R(n1,?a),x1+1,x2,x,n-1)
            -S`i'(R(?a),x1+1,x)*fac`i'(x2,x)*den`i'(x1+1,x)^(abs_(n1))
                *sign(x1)^theta_(-n1)*sign`i'(x)^theta_(-n1);
endrepeat;
*
*	Theta constraint from Sven
*
id  f2(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*fac`i'(x2,x)*theta_(x1+x-1);
*id  f2(R(?a),x1?,x2?,x?,0) = S`i'(R(?a),x1,x)*fac`i'(x2,x);
id  sign`i'(-j`i') = sign`i'(j`i');
id  sign`i'(j`i')*sign`i'(j`i') = 1;
*
#endprocedure
*
*--#] synchfs : 
*--#[ synchss :
*
#procedure synchss(i)
*
*   Synchronization of products of S-functions
*
repeat;
    id,once,S`i'(x1?,x2?,x3?) = f1(x1,x2,x3);
    repeat;
        id,f1(x1?,x2?,x3?)*S`i'(x4?,x5?,x3?) = f2(x1,x2,x4,x5,x3,x2-x5);
        if ( match(f2(?a,x?int_)) );
            repeat;
                id  f2(R(n1?,?a),x2?,R(n2?,?b),x5?,x3?,x6?pos_) =
                    +f2(R(n1,?a),x2,R(n2,?b),x5+1,x3,x6-1)
                    -f2(R(n1,?a),x2,R(?b),x5+1,x3,x6-1)
                        *den`i'(x5+1,x3)^abs_(n2)*sign(x5+1)^theta_(-n2)
                            *sign`i'(j`i')^theta_(-n2);
            endrepeat;
            repeat;
                id  f2(R(n1?,?a),x2?,R(n2?,?b),x5?,x3?,x6?neg_) =
                    +f2(R(n1,?a),x2+1,R(n2,?b),x5,x3,x6+1)
                    -f2(R(?a),x2+1,R(n2,?b),x5,x3,x6+1)
                        *den`i'(x2+1,x3)^abs_(n1)*sign(x2+1)^theta_(-n1)
                            *sign`i'(j`i')^theta_(-n1);
            endrepeat;
            id  f2(x1?,x2?,x4?,x5?,x3?,n?) =
                    S`i'(x1,x2,x3)*S`i'(x4,x5,x3);
            id  S`i'(R,x1?,x2?) = 1;
            #call basis2(S`i')
        else;
            id  f2(x1?,x2?,x4?,x5?,x3?,x6?) = f1(x1,x2,x3)*f3(x4,x5,x3);
        endif;
    endrepeat;
    id  f3(x4?,x5?,x3?) = S`i'(x4,x5,x3);
    id  f1(?a) = f4(?a);
endrepeat;
id  f4(?a) = S`i'(?a);
#endprocedure
*
*--#] synchss : 
*--#[ table1 :
*
#procedure table1
*
*   Constants: Sinf is the basic divergence ~ln_(inf) = lim(n->inf)*S_1(n)
*              ln2 = ln_(2)
*   File by J. Vermaseren 5-jun-1998
*
S   Sinf,ln2;
CTable,relax,Stab1(-1:1);
Fill Stab1(1)  = Sinf;
Fill Stab1(-1) = -ln2;
#endprocedure
*
*--#] table1 : 
*--#[ table2 :
*
#procedure table2
*
*   New constant: z2 = zeta_2 = pi_^2/6
*   File by J. Vermaseren, 5-jun-1998
*
S   z2;
CTable,relax,Stab2(-1:1,-1:1);
Fill Stab2(0,1) = z2;
Fill Stab2(0,-1) = -z2/2;
Fill Stab2(1,1) = + 1/2*z2 + 1/2*Sinf^2;
Fill Stab2(1,-1) = - 1/2*ln2^2 - Sinf*ln2;
Fill Stab2(-1,1) = - 1/2*z2 + 1/2*ln2^2;
Fill Stab2(-1,-1) = + 1/2*z2 + 1/2*ln2^2;
#endprocedure
*
*--#] table2 : 
*--#[ table3 :
*
#procedure table3
*
*   New constant: z3 = zeta_3
*   File by J. Vermaseren, 5-jun-1998
*
S   z3;
CTable,relax,Stab3(-1:1,-1:1,-1:1);
Fill Stab3(0,0,1) = + z3;
Fill Stab3(0,0,-1) = - 3/4*z3;
Fill Stab3(0,1,1) = + 2*z3;
Fill Stab3(0,1,-1) = - 3/2*z2*ln2 + 1/4*z3;
Fill Stab3(0,-1,1) = - 5/8*z3;
Fill Stab3(0,-1,-1) = + 3/2*z2*ln2 - 5/8*z3;
Fill Stab3(1,0,1) = - z3 + Sinf*z2;
Fill Stab3(1,0,-1) = - 1/8*z3 - 1/2*Sinf*z2;
Fill Stab3(-1,0,1) = + 1/2*z2*ln2 - z3;
Fill Stab3(-1,0,-1) = - z2*ln2 + 13/8*z3;
Fill Stab3(1,1,1) = + 1/3*z3 + 1/2*Sinf*z2 + 1/6*Sinf^3;
Fill Stab3(1,1,-1) = - 1/2*z2*ln2 - 1/6*ln2^3 - 1/2*Sinf*ln2^2
                         - 1/2*Sinf^2*ln2;
Fill Stab3(1,-1,1) = - 1/2*z2*ln2 + 1/8*z3 + 1/3*ln2^3 - 1/2*Sinf*z2
                         + 1/2*Sinf*ln2^2;
Fill Stab3(1,-1,-1) = + 1/2*z2*ln2 - 7/8*z3 + 1/3*ln2^3 + 1/2*Sinf*z2
                         + 1/2*Sinf*ln2^2;
Fill Stab3(-1,1,1) = + 1/2*z2*ln2 - 7/8*z3 - 1/6*ln2^3;
Fill Stab3(-1,1,-1) = + 1/2*z2*ln2 + 1/8*z3 - 1/6*ln2^3;
Fill Stab3(-1,-1,1) = - 1/2*z2*ln2 + 7/4*z3 - 1/6*ln2^3;
Fill Stab3(-1,-1,-1) = - 1/2*z2*ln2 - 1/4*z3 - 1/6*ln2^3;
#endprocedure
*
*--#] table3 : 
*--#[ table4 :
*
#procedure table4
*
*   New constant: li4half = Li_4(1/2) = -S(R(-1,1,1,1),inf)
*   File by J. Vermaseren, 5-jun-1998
*
S   li4half;
CTable,relax,Stab4(-1:1,-1:1,-1:1,-1:1);
Fill Stab4(-1,-1,-1,-1) = 1/4*z2*ln2^2+9/40*z2^2+1/4*z3*ln2+1/24*ln2^4;
Fill Stab4(-1,-1,-1,1) = 1/4*z2*ln2^2-19/40*z2^2+1/4*z3*ln2+1/24*ln2^4;
Fill Stab4(-1,-1,0,-1) = -1/4*z2*ln2^2-3/5*z2^2+z3*ln2;
Fill Stab4(-1,-1,0,1) = -1/4*z2*ln2^2-3/8*z2^2+z3*ln2+1/8*ln2^4+3*li4half;
Fill Stab4(-1,-1,1,-1) = -1/2*z2*ln2^2-6/5*z2^2+7/8*z3*ln2+1/6*ln2^4+3*li4half;
Fill Stab4(-1,-1,1,1) = -1/2*z2*ln2^2+7/8*z3*ln2+1/6*ln2^4+3*li4half;
Fill Stab4(-1,0,-1,-1) = 1/2*z2*ln2^2-7/5*z2^2+5/8*z3*ln2+1/6*ln2^4+4*li4half;
Fill Stab4(-1,0,-1,1) = -3/4*z2*ln2^2-9/40*z2^2+5/8*z3*ln2+1/8*ln2^4+3*li4half;
Fill Stab4(-1,0,0,-1) = -1/2*z2*ln2^2-1/5*z2^2+3/4*z3*ln2+1/12*ln2^4+2*li4half;
Fill Stab4(-1,0,0,1) = -19/40*z2^2+3/4*z3*ln2;
Fill Stab4(-1,0,1,-1) = -1/2*z2*ln2^2+5/4*z2^2-1/4*z3*ln2-1/6*ln2^4-4*li4half;
Fill Stab4(-1,0,1,1) = 1/4*z2*ln2^2-1/40*z2^2-1/4*z3*ln2-1/24*ln2^4-li4half;
Fill Stab4(-1,1,-1,-1) = -1/4*z2*ln2^2-1/8*z2^2-1/8*z3*ln2+1/24*ln2^4;
Fill Stab4(-1,1,-1,1) = -1/4*z2*ln2^2+3/8*z2^2-1/8*z3*ln2+1/24*ln2^4;
Fill Stab4(-1,1,0,-1) = -1/5*z2^2+1/8*z3*ln2+1/12*ln2^4+2*li4half;
Fill Stab4(-1,1,0,1) = -1/20*z2^2+1/8*z3*ln2-1/24*ln2^4-li4half;
Fill Stab4(-1,1,1,-1) = 2/5*z2^2-li4half;
Fill Stab4(-1,1,1,1) = -li4half;
Fill Stab4(0,-1,-1,-1) = -1/2*z2*ln2^2+7/5*z2^2-21/8*z3*ln2-1/6*ln2^4-4*li4half;
Fill Stab4(0,-1,-1,1) = 39/40*z2^2-1/8*ln2^4-3*li4half;
Fill Stab4(0,-1,0,-1) = 13/40*z2^2;
Fill Stab4(0,-1,0,1) = z2*ln2^2+51/40*z2^2-7/2*z3*ln2-1/6*ln2^4-4*li4half;
Fill Stab4(0,-1,1,-1) = 3/4*z2*ln2^2+3/40*z2^2;
Fill Stab4(0,-1,1,1) = 1/4*z2*ln2^2+1/8*z2^2-7/8*z3*ln2-1/24*ln2^4-li4half;
Fill Stab4(0,0,-1,-1) = 1/2*z2*ln2^2+3/5*z2^2-1/12*ln2^4-2*li4half;
Fill Stab4(0,0,-1,1) = -1/2*z2*ln2^2-11/10*z2^2+7/4*z3*ln2+1/12*ln2^4+2*li4half;
Fill Stab4(0,0,0,-1) = -7/20*z2^2;
Fill Stab4(0,0,0,1) = 2/5*z2^2;
Fill Stab4(0,0,1,-1) = 1/8*z2^2-7/4*z3*ln2;
Fill Stab4(0,0,1,1) = 1/2*z2^2;
Fill Stab4(0,1,-1,-1) = 5/4*z2*ln2^2+1/40*z2^2+1/24*ln2^4+li4half;
Fill Stab4(0,1,-1,1) = -1/4*z2*ln2^2-2*z2^2+21/8*z3*ln2+1/6*ln2^4+4*li4half;
Fill Stab4(0,1,0,-1) = -z2*ln2^2-17/8*z2^2+7/2*z3*ln2+1/6*ln2^4+4*li4half;
Fill Stab4(0,1,0,1) = 7/10*z2^2;
Fill Stab4(0,1,1,-1) = -3/2*z2*ln2^2-6/5*z2^2+7/8*z3*ln2+1/8*ln2^4+3*li4half;
Fill Stab4(0,1,1,1) = 6/5*z2^2;
Fill Stab4(1,-1,-1,-1) = -1/2*z2*ln2*Sinf+1/4*z2*ln2^2+6/5*z2^2-2*z3*ln2
             -1/4*z3*Sinf-1/6*ln2^3*Sinf-1/4*ln2^4-3*li4half;
Fill Stab4(1,-1,-1,1) = -1/2*z2*ln2*Sinf+1/4*z2*ln2^2+7/4*z3*Sinf
             -1/6*ln2^3*Sinf-1/4*ln2^4-3*li4half;
Fill Stab4(1,-1,0,-1) = -z2*ln2*Sinf+1/4*z2*ln2^2+11/20*z2^2+13/8*z3*Sinf
             -1/8*ln2^4-3*li4half;
Fill Stab4(1,-1,0,1) = 1/2*z2*ln2*Sinf+3/4*z2*ln2^2+7/8*z2^2-21/8*z3*ln2
             -z3*Sinf-1/12*ln2^4-2*li4half;
Fill Stab4(1,-1,1,-1) = 1/2*z2*ln2*Sinf+1/2*z2*ln2^2-1/20*z2^2+1/8*z3*Sinf
             -1/6*ln2^3*Sinf-1/8*ln2^4;
Fill Stab4(1,-1,1,1) = 1/2*z2*ln2*Sinf+1/2*z2*ln2^2+1/20*z2^2-z3*ln2
             -7/8*z3*Sinf-1/6*ln2^3*Sinf-1/8*ln2^4;
Fill Stab4(1,0,-1,-1) = 3/2*z2*ln2*Sinf-1/4*z2*ln2^2-1/8*z2^2-5/8*z3*Sinf
             +1/24*ln2^4+li4half;
Fill Stab4(1,0,-1,1) = -3/40*z2^2-5/8*z3*Sinf;
Fill Stab4(1,0,0,-1) = 1/2*z2*ln2^2+3/4*z2^2-7/4*z3*ln2-3/4*z3*Sinf-1/12*ln2^4
             -2*li4half;
Fill Stab4(1,0,0,1) = -1/10*z2^2+z3*Sinf;
Fill Stab4(1,0,1,-1) = -3/2*z2*ln2*Sinf+3/4*z2*ln2^2+6/5*z2^2-7/4*z3*ln2
             +1/4*z3*Sinf-1/8*ln2^4-3*li4half;
Fill Stab4(1,0,1,1) = -6/5*z2^2+2*z3*Sinf;
Fill Stab4(1,1,-1,-1) = 1/2*z2*ln2*Sinf+1/4*z2*ln2^2+1/4*z2*Sinf^2+1/4*z2^2
             -7/8*z3*Sinf+1/4*ln2^2*Sinf^2+1/3*ln2^3*Sinf+1/6*ln2^4+li4half;
Fill Stab4(1,1,-1,1) = -1/2*z2*ln2*Sinf-1/4*z2*ln2^2-1/4*z2*Sinf^2-13/20*z2^2
             +z3*ln2+1/8*z3*Sinf+1/4*ln2^2*Sinf^2+1/3*ln2^3*Sinf+1/6*ln2^4+li4half;
Fill Stab4(1,1,0,-1) = -1/4*z2*ln2^2-1/4*z2*Sinf^2-13/20*z2^2+7/8*z3*ln2
             -1/8*z3*Sinf+1/24*ln2^4+li4half;
Fill Stab4(1,1,0,1) = 1/2*z2*Sinf^2+9/10*z2^2-z3*Sinf;
Fill Stab4(1,1,1,-1) = -1/2*z2*ln2*Sinf-1/4*z2*ln2^2-1/3*z3*ln2-1/6*ln2*Sinf^3
             -1/4*ln2^2*Sinf^2-1/6*ln2^3*Sinf-1/24*ln2^4;
Fill Stab4(1,1,1,1) = 1/4*z2*Sinf^2+9/40*z2^2+1/3*z3*Sinf+1/24*Sinf^4;
#endprocedure
*
*--#] table4 : 
*--#[ table5 :
*
#procedure table5
*
*   New constants: li5half = Li_5(1/2) = -S(R(-1,1,1,1,1),inf)
*                  z5 = zeta_5
*   File by J. Vermaseren, 5-jun-1998
*
S   z5,li5half;
CTable,relax,Stab5(-1:1,-1:1,-1:1,-1:1,-1:1);
Fill Stab5(-1,-1,-1,-1,-1) = -1/8*z2*z3-1/12*z2*ln2^3-9/40*z2^2
         *ln2-1/8*z3*ln2^2-3/16*z5-1/120*ln2^5;
Fill Stab5(-1,-1,-1,-1,1) = -1/8*z2*z3-1/12*z2*ln2^3-9/40*z2^2*
         ln2-1/8*z3*ln2^2+29/16*z5-1/120*ln2^5;
Fill Stab5(-1,-1,-1,0,-1) = -3/4*z2*z3+1/12*z2*ln2^3+3/8*z2^2*
         ln2-1/2*z3*ln2^2+29/64*z5-1/40*ln2^5+3*li5half;
Fill Stab5(-1,-1,-1,0,1) = -3/8*z2*z3+1/12*z2*ln2^3+3/5*z2^2*
         ln2-1/2*z3*ln2^2-z5;
Fill Stab5(-1,-1,-1,1,-1) = -23/16*z2*z3+5/12*z2*ln2^3+19/40*
         z2^2*ln2-23/16*z3*ln2^2+375/64*z5-3*ln2*li4half-13/120*ln2^5
         -3*li5half;
Fill Stab5(-1,-1,-1,1,1) = 9/16*z2*z3+5/12*z2*ln2^3+19/40*z2^2*
         ln2-23/16*z3*ln2^2+23/64*z5-3*ln2*li4half-13/120*ln2^5-3*
         li5half;
Fill Stab5(-1,-1,0,-1,-1) = -13/8*z2*z3+5/6*z2*ln2^3-41/40*z2^2
         *ln2-13/8*z3*ln2^2+845/64*z5-4*ln2*li4half-3/40*ln2^5-11*
         li5half;
Fill Stab5(-1,-1,0,-1,1) = z2*z3+7/12*z2*ln2^3+1/40*z2^2*ln2-13/
         8*z3*ln2^2+101/64*z5-4*ln2*li4half-1/8*ln2^5-5*li5half;
Fill Stab5(-1,-1,0,0,-1) = 1/8*z2*z3+19/40*z2^2*ln2-3/8*z3*ln2^2
         -15/8*z5;
Fill Stab5(-1,-1,0,0,1) = -11/8*z2*z3+1/6*z2*ln2^3+1/5*z2^2*ln2
         -3/8*z3*ln2^2+159/64*z5-1/60*ln2^5+2*li5half;
Fill Stab5(-1,-1,0,1,-1) = 1/8*z2*z3-1/3*z2*ln2^3+47/40*z2^2*ln2
         +1/8*z3*ln2^2-61/8*z5+ln2*li4half-1/40*ln2^5+8*li5half;
Fill Stab5(-1,-1,0,1,1) = 1/8*z2*z3+1/12*z2*ln2^3+9/40*z2^2*ln2
         +1/8*z3*ln2^2-29/16*z5+ln2*li4half+1/120*ln2^5+4*li5half;
Fill Stab5(-1,-1,1,-1,-1) = -7/16*z2*z3+1/6*z2*ln2^3+6/5*z2^2*
         ln2-7/16*z3*ln2^2-81/64*z5-1/30*ln2^5+3*li5half;
Fill Stab5(-1,-1,1,-1,1) = 9/16*z2*z3+1/6*z2*ln2^3+6/5*z2^2*ln2
         -7/16*z3*ln2^2-369/64*z5-1/30*ln2^5+3*li5half;
Fill Stab5(-1,-1,1,0,-1) = 3/8*z2*z3-1/12*z2*ln2^3+3/5*z2^2*ln2
         -1/16*z3*ln2^2-125/32*z5+ln2*li4half+1/30*ln2^5+li5half;
Fill Stab5(-1,-1,1,0,1) = -15/16*z2*z3-1/12*z2*ln2^3+3/8*z2^2*
         ln2-1/16*z3*ln2^2+29/64*z5+ln2*li4half+1/120*ln2^5+4*
         li5half;
Fill Stab5(-1,-1,1,1,-1) = -4*z5+ln2*li4half+4*li5half;
Fill Stab5(-1,-1,1,1,1) = ln2*li4half+4*li5half;
Fill Stab5(-1,0,-1,-1,-1) = 21/16*z2*z3-17/12*z2*ln2^3+21/8*z2^2*
         ln2+21/16*z3*ln2^2-911/64*z5+4*ln2*li4half+7/120*ln2^5+13*
         li5half;
Fill Stab5(-1,0,-1,-1,1) = -2/3*z2*ln2^3+27/8*z2^2*ln2-911/64*
         z5+4*ln2*li4half+7/120*ln2^5+13*li5half;
Fill Stab5(-1,0,-1,0,-1) = 5/16*z2*z3-1/3*z2*ln2^3+17/8*z2^2*ln2
         -331/32*z5+4*ln2*li4half+1/10*ln2^5+8*li5half;
Fill Stab5(-1,0,-1,0,1) = 9/8*z2*z3-2/3*z2*ln2^3-7/10*z2^2*ln2+
         7/4*z3*ln2^2-259/64*z5+4*ln2*li4half+2/15*ln2^5+4*li5half;
Fill Stab5(-1,0,-1,1,-1) = 3/4*z2*ln2^3+1/40*z2^2*ln2-99/32*z5+
         ln2*li4half+1/60*ln2^5+3*li5half;
Fill Stab5(-1,0,-1,1,1) = 7/16*z2*z3-1/6*z2*ln2^3-6/5*z2^2*ln2+
         7/16*z3*ln2^2+81/64*z5+ln2*li4half+1/30*ln2^5+li5half;
Fill Stab5(-1,0,0,-1,-1) = 1/2*z2*ln2^3-2/5*z2^2*ln2+15/32*z5-2
         *ln2*li4half-1/12*ln2^5;
Fill Stab5(-1,0,0,-1,1) = -7/8*z2*z3+1/3*z2*ln2^3-1/2*z2^2*ln2
         -7/8*z3*ln2^2+85/16*z5-2*ln2*li4half-1/15*ln2^5-2*li5half;
Fill Stab5(-1,0,0,0,-1) = -3/4*z2*z3-2/5*z2^2*ln2+91/32*z5;
Fill Stab5(-1,0,0,0,1) = 3/8*z2*z3+7/20*z2^2*ln2-2*z5;
Fill Stab5(-1,0,0,1,-1) = -1/3*z2*ln2^3-13/40*z2^2*ln2+27/8*z5
         +1/30*ln2^5-4*li5half;
Fill Stab5(-1,0,0,1,1) = 7/8*z2*z3+1/6*z2*ln2^3+11/10*z2^2*ln2-
         7/8*z3*ln2^2-311/64*z5-1/60*ln2^5+2*li5half;
Fill Stab5(-1,0,1,-1,-1) = 7/6*z2*ln2^3-81/20*z2^2*ln2+245/16*z5
         -4*ln2*li4half-1/30*ln2^5-16*li5half;
Fill Stab5(-1,0,1,-1,1) = -21/16*z2*z3+7/12*z2*ln2^3-49/20*z2^2
         *ln2-21/16*z3*ln2^2+521/32*z5-4*ln2*li4half-1/20*ln2^5-14*
         li5half;
Fill Stab5(-1,0,1,0,-1) = -3/2*z2*z3+2/3*z2*ln2^3-13/40*z2^2*
         ln2-7/4*z3*ln2^2+129/16*z5-4*ln2*li4half-2/15*ln2^5-4*
         li5half;
Fill Stab5(-1,0,1,0,1) = -1/8*z2*z3+1/3*z2*ln2^3-51/40*z2^2*ln2
         +227/32*z5-4*ln2*li4half-1/10*ln2^5-8*li5half;
Fill Stab5(-1,0,1,1,-1) = -21/16*z2*z3+6/5*z2^2*ln2-21/16*z3*
         ln2^2+87/32*z5-3*ln2*li4half-1/8*ln2^5;
Fill Stab5(-1,0,1,1,1) = 7/8*z2*z3+5/12*z2*ln2^3-1/8*z2^2*ln2-7/
         8*z3*ln2^2+81/64*z5-3*ln2*li4half-11/120*ln2^5-4*li5half;
Fill Stab5(-1,1,-1,-1,-1) = 13/8*z2*z3-5/12*z2*ln2^3+1/8*z2^2*ln2
         +11/8*z3*ln2^2-369/64*z5+3*ln2*li4half+11/120*ln2^5+3*
         li5half;
Fill Stab5(-1,1,-1,-1,1) = -11/8*z2*z3-5/12*z2*ln2^3+1/8*z2^2*
         ln2+11/8*z3*ln2^2-81/64*z5+3*ln2*li4half+11/120*ln2^5+3*
         li5half;
Fill Stab5(-1,1,-1,0,-1) = -7/8*z2*z3-1/3*z2*ln2^3+1/20*z2^2*
         ln2+13/16*z3*ln2^2-33/64*z5+2*ln2*li4half+3/40*ln2^5+
         li5half;
Fill Stab5(-1,1,-1,0,1) = 31/16*z2*z3-1/3*z2*ln2^3+1/5*z2^2*ln2
         +13/16*z3*ln2^2-405/64*z5+2*ln2*li4half+1/20*ln2^5+4*
         li5half;
Fill Stab5(-1,1,-1,1,-1) = -1/16*z2*z3+1/12*z2*ln2^3-3/8*z2^2*
         ln2+1/16*z3*ln2^2+3/64*z5-1/120*ln2^5;
Fill Stab5(-1,1,-1,1,1) = 15/16*z2*z3+1/12*z2*ln2^3-3/8*z2^2*ln2
         +1/16*z3*ln2^2-29/64*z5-1/120*ln2^5;
Fill Stab5(-1,1,0,-1,-1) = 5/16*z2*z3-1/6*z2*ln2^3+31/20*z2^2*ln2
         -5/16*z3*ln2^2-457/64*z5-7/120*ln2^5+7*li5half;
Fill Stab5(-1,1,0,-1,1) = 5/16*z2*z3+1/4*z2*ln2^3+9/40*z2^2*ln2
         -5/16*z3*ln2^2-29/16*z5-1/40*ln2^5+3*li5half;
Fill Stab5(-1,1,0,0,-1) = 9/8*z2*z3-1/6*z2*ln2^3+1/5*z2^2*ln2+1/
         2*z3*ln2^2-153/32*z5+2*ln2*li4half+1/20*ln2^5+4*li5half;
Fill Stab5(-1,1,0,0,1) = -7/16*z2*z3-1/3*z2*ln2^3+19/40*z2^2*
         ln2+1/2*z3*ln2^2-151/64*z5+2*ln2*li4half+1/15*ln2^5+2*
         li5half;
Fill Stab5(-1,1,0,1,-1) = 19/16*z2*z3-1/3*z2*ln2^3-7/5*z2^2*ln2
         +23/16*z3*ln2^2+35/32*z5+3*ln2*li4half+19/120*ln2^5-4*
         li5half;
Fill Stab5(-1,1,0,1,1) = -23/16*z2*z3-7/12*z2*ln2^3+1/40*z2^2*
         ln2+23/16*z3*ln2^2-23/64*z5+3*ln2*li4half+13/120*ln2^5+2*
         li5half;
Fill Stab5(-1,1,1,-1,-1) = 7/16*z2*z3+1/6*z2*ln2^3-2/5*z2^2*ln2
         -7/16*z3*ln2^2+27/32*z5-ln2*li4half-1/30*ln2^5-2*li5half;
Fill Stab5(-1,1,1,-1,1) = -9/16*z2*z3+1/6*z2*ln2^3-2/5*z2^2*ln2
         -7/16*z3*ln2^2+123/32*z5-ln2*li4half-1/30*ln2^5-2*li5half;
Fill Stab5(-1,1,1,0,-1) = -3/8*z2*z3+1/6*z2*ln2^3+1/5*z2^2*ln2
         -1/2*z3*ln2^2+15/16*z5-ln2*li4half-1/20*ln2^5+li5half;
Fill Stab5(-1,1,1,0,1) = 1/2*z2*z3+1/6*z2*ln2^3+1/20*z2^2*ln2-1/
         2*z3*ln2^2-1/32*z5-ln2*li4half-1/40*ln2^5-2*li5half;
Fill Stab5(-1,1,1,1,-1) = z5-li5half;
Fill Stab5(-1,1,1,1,1) = -li5half;
Fill Stab5(0,-1,-1,-1,-1) = 27/16*z2*z3+7/12*z2*ln2^3-11/8*z2^2*
         ln2+21/16*z3*ln2^2+101/64*z5+1/24*ln2^5-5*li5half;
Fill Stab5(0,-1,-1,-1,1) = -21/16*z2*z3+7/12*z2*ln2^3-17/5*z2^2
         *ln2+21/16*z3*ln2^2+845/64*z5-3*ln2*li4half-1/30*ln2^5-11*
         li5half;
Fill Stab5(0,-1,-1,0,-1) = -13/16*z2*z3+2/3*z2*ln2^3-17/5*z2^2*
         ln2+547/32*z5-8*ln2*li4half-1/5*ln2^5-16*li5half;
Fill Stab5(0,-1,-1,0,1) = 25/8*z2*z3+3/8*z2^2*ln2-363/64*z5;
Fill Stab5(0,-1,-1,1,-1) = -1/3*z2*ln2^3-87/40*z2^2*ln2+221/32*
         z5-ln2*li4half+1/60*ln2^5-7*li5half;
Fill Stab5(0,-1,-1,1,1) = 21/16*z2*z3+9/40*z2^2*ln2-23/64*z5+1/
         40*ln2^5-3*li5half;
Fill Stab5(0,-1,0,-1,-1) = -1/3*z2*ln2^3+19/20*z2^2*ln2-123/16*
         z5+4*ln2*li4half+1/10*ln2^5+8*li5half;
Fill Stab5(0,-1,0,-1,1) = 15/16*z2*z3-29/32*z5;
Fill Stab5(0,-1,0,0,-1) = 21/8*z2*z3-67/16*z5;
Fill Stab5(0,-1,0,0,1) = -3/4*z2*z3+21/32*z5;
Fill Stab5(0,-1,0,1,-1) = 11/8*z2*z3-1/3*z2*ln2^3-19/20*z2^2*ln2
         +7/4*z3*ln2^2+33/32*z5+1/30*ln2^5-4*li5half;
Fill Stab5(0,-1,0,1,1) = -7/4*z2*z3-2/3*z2*ln2^3+7/4*z3*ln2^2
         -89/64*z5+4*ln2*li4half+2/15*ln2^5+4*li5half;
Fill Stab5(0,-1,1,-1,-1) = -11/12*z2*ln2^3+53/40*z2^2*ln2-457/
         64*z5+3*ln2*li4half+1/15*ln2^5+7*li5half;
Fill Stab5(0,-1,1,-1,1) = -3/16*z2*z3-1/4*z2*ln2^3+9/10*z2^2*
         ln2-29/16*z5-1/40*ln2^5+3*li5half;
Fill Stab5(0,-1,1,0,-1) = 1/16*z2*z3+5/8*z5;
Fill Stab5(0,-1,1,0,1) = 1/16*z2*z3-53/64*z5;
Fill Stab5(0,-1,1,1,-1) = 7/16*z2*z3+1/6*z2*ln2^3-1/20*z2^2*ln2
         +7/16*z3*ln2^2+1/8*z5+1/120*ln2^5-li5half;
Fill Stab5(0,-1,1,1,1) = -7/16*z2*z3-1/6*z2*ln2^3+7/16*z3*ln2^2
         -27/32*z5+ln2*li4half+1/30*ln2^5+li5half;
Fill Stab5(0,0,-1,-1,-1) = -1/2*z2*z3-1/2*z2*ln2^3-19/40*z2^2*
         ln2+15/32*z5+2*ln2*li4half+1/12*ln2^5;
Fill Stab5(0,0,-1,-1,1) = -13/8*z2*z3-1/6*z2*ln2^3-1/10*z2^2*
         ln2+85/16*z5+1/60*ln2^5-2*li5half;
Fill Stab5(0,0,-1,0,-1) = -9/4*z2*z3+83/16*z5;
Fill Stab5(0,0,-1,0,1) = -5/8*z2*z3+11/32*z5;
Fill Stab5(0,0,-1,1,-1) = -3/4*z2*z3+1/3*z2*ln2^3+17/10*z2^2*
         ln2-7/8*z3*ln2^2-39/16*z5-1/30*ln2^5+4*li5half;
Fill Stab5(0,0,-1,1,1) = 3/8*z2*z3+1/3*z2*ln2^3-7/8*z3*ln2^2+15/
         32*z5-2*ln2*li4half-1/15*ln2^5-2*li5half;
Fill Stab5(0,0,0,-1,-1) = 3/4*z2*z3+3/4*z2^2*ln2-59/32*z5;
Fill Stab5(0,0,0,-1,1) = 1/2*z2*z3-59/32*z5;
Fill Stab5(0,0,0,0,-1) = -15/16*z5;
Fill Stab5(0,0,0,0,1) = z5;
Fill Stab5(0,0,0,1,-1) = -3/8*z2*z3-3/4*z2^2*ln2+17/16*z5;
Fill Stab5(0,0,0,1,1) = -z2*z3+3*z5;
Fill Stab5(0,0,1,-1,-1) = 15/8*z2*z3+1/6*z2*ln2^3+19/40*z2^2*ln2
         +7/8*z3*ln2^2-311/64*z5-1/60*ln2^5+2*li5half;
Fill Stab5(0,0,1,-1,1) = -1/16*z2*z3+1/6*z2*ln2^3-49/40*z2^2*
         ln2+7/8*z3*ln2^2+27/8*z5-2*ln2*li4half-1/20*ln2^5-4*li5half
         ;
Fill Stab5(0,0,1,0,-1) = 1/4*z2*z3-51/32*z5;
Fill Stab5(0,0,1,0,1) = 3*z2*z3-9/2*z5;
Fill Stab5(0,0,1,1,-1) = -1/16*z2*z3-1/3*z2*ln2^3-3/8*z2^2*ln2
         -125/64*z5+2*ln2*li4half+1/15*ln2^5+2*li5half;
Fill Stab5(0,0,1,1,1) = z2*z3-1/2*z5;
Fill Stab5(0,1,-1,-1,-1) = -3/8*z2*z3-13/12*z2*ln2^3+11/8*z2^2*
         ln2-61/8*z5+3*ln2*li4half+7/120*ln2^5+8*li5half;
Fill Stab5(0,1,-1,-1,1) = -5/12*z2*ln2^3+19/20*z2^2*ln2-29/16*
         z5-1/30*ln2^5+4*li5half;
Fill Stab5(0,1,-1,0,-1) = -z2*z3-3/8*z2^2*ln2+257/64*z5;
Fill Stab5(0,1,-1,0,1) = -z2*z3-2/3*z2*ln2^3+17/5*z2^2*ln2-
         507/32*z5+8*ln2*li4half+1/5*ln2^5+16*li5half;
Fill Stab5(0,1,-1,1,-1) = -21/16*z2*z3+1/3*z2*ln2^3+83/40*z2^2*
         ln2-21/16*z3*ln2^2-85/64*z5-1/30*ln2^5+4*li5half;
Fill Stab5(0,1,-1,1,1) = 17/8*z2^2*ln2-21/16*z3*ln2^2-61/8*z5+
         ln2*li4half-1/120*ln2^5+6*li5half;
Fill Stab5(0,1,0,-1,-1) = -7/4*z2*z3+1/3*z2*ln2^3+113/40*z2^2*
         ln2-7/4*z3*ln2^2-89/64*z5-1/30*ln2^5+4*li5half;
Fill Stab5(0,1,0,-1,1) = 13/16*z2*z3+2/3*z2*ln2^3-7/4*z3*ln2^2+
         33/32*z5-4*ln2*li4half-2/15*ln2^5-4*li5half;
Fill Stab5(0,1,0,0,-1) = -1/8*z2*z3-41/32*z5;
Fill Stab5(0,1,0,0,1) = -2*z2*z3+11/2*z5;
Fill Stab5(0,1,0,1,-1) = 3/8*z2*z3+1/3*z2*ln2^3-113/40*z2^2*ln2
         +125/16*z5-4*ln2*li4half-1/10*ln2^5-8*li5half;
Fill Stab5(0,1,0,1,1) = 2*z5;
Fill Stab5(0,1,1,-1,-1) = -7/16*z2*z3+11/12*z2*ln2^3+49/40*z2^2
         *ln2-7/16*z3*ln2^2-23/64*z5-1/60*ln2^5+2*li5half;
Fill Stab5(0,1,1,-1,1) = 5/8*z2*z3+11/12*z2*ln2^3-4/5*z2^2*ln2-
         7/16*z3*ln2^2+35/32*z5-3*ln2*li4half-11/120*ln2^5-4*li5half;
Fill Stab5(0,1,1,0,-1) = 5/16*z2*z3-177/64*z5;
Fill Stab5(0,1,1,0,1) = -z2*z3+9/2*z5;
Fill Stab5(0,1,1,1,-1) = -1/3*z2*ln2^3-12/5*z2^2*ln2+4*z5-ln2
         *li4half-1/120*ln2^5-4*li5half;
Fill Stab5(0,1,1,1,1) = 4*z5;
Fill Stab5(1,-1,-1,-1,-1) = z2*z3+1/4*z2*ln2^2*Sinf-39/40*z2^2*
         ln2+9/40*z2^2*Sinf+1/4*z3*ln2*Sinf+9/8*z3*ln2^2+23/64*z5+1/
         24*ln2^4*Sinf+7/120*ln2^5-3*li5half;
Fill Stab5(1,-1,-1,-1,1) = -z2*z3+1/4*z2*ln2^2*Sinf-67/40*z2^2*
         ln2-19/40*z2^2*Sinf+1/4*z3*ln2*Sinf+9/8*z3*ln2^2+375/64*z5+
         1/24*ln2^4*Sinf+7/120*ln2^5-3*li5half;
Fill Stab5(1,-1,-1,0,-1) = -7/8*z2*z3-1/4*z2*ln2^2*Sinf+1/6*z2*
         ln2^3-59/40*z2^2*ln2-3/5*z2^2*Sinf+z3*ln2*Sinf+1/2*z3*ln2^2
         +247/32*z5-3*ln2*li4half-1/12*ln2^5-5*li5half;
Fill Stab5(1,-1,-1,0,1) = 7/4*z2*z3-1/4*z2*ln2^2*Sinf-1/6*z2*
         ln2^3-37/40*z2^2*ln2-3/8*z2^2*Sinf+z3*ln2*Sinf+1/2*z3*ln2^2
         +29/64*z5+1/8*ln2^4*Sinf+1/20*ln2^5+3*Sinf*li4half-6*
         li5half;
Fill Stab5(1,-1,-1,1,-1) = -1/2*z2*ln2^2*Sinf-1/4*z2*ln2^3-6/5*
         z2^2*ln2-6/5*z2^2*Sinf+7/8*z3*ln2*Sinf+7/16*z3*ln2^2+6*z5+1/
         6*ln2^4*Sinf+1/12*ln2^5+3*Sinf*li4half-6*li5half;
Fill Stab5(1,-1,-1,1,1) = -1/2*z2*ln2^2*Sinf-1/4*z2*ln2^3+7/8*
         z3*ln2*Sinf+7/16*z3*ln2^2+1/6*ln2^4*Sinf+1/12*ln2^5+3*Sinf*
         li4half-6*li5half;
Fill Stab5(1,-1,0,-1,-1) = 1/2*z2*ln2^2*Sinf-1/12*z2*ln2^3-91/40*
         z2^2*ln2-7/5*z2^2*Sinf+5/8*z3*ln2*Sinf+5/16*z3*ln2^2+221/32*
         z5+ln2*li4half+1/6*ln2^4*Sinf+1/10*ln2^5+4*Sinf*li4half-7*
         li5half;
Fill Stab5(1,-1,0,-1,1) = -3/4*z2*ln2^2*Sinf-1/4*z2*ln2^3+39/40
         *z2^2*ln2-9/40*z2^2*Sinf+5/8*z3*ln2*Sinf+5/16*z3*ln2^2-23/64*
         z5+1/8*ln2^4*Sinf+1/40*ln2^5+3*Sinf*li4half-3*li5half;
Fill Stab5(1,-1,0,0,-1) = 13/8*z2*z3-1/2*z2*ln2^2*Sinf-1/6*z2*
         ln2^3-1/10*z2^2*ln2-1/5*z2^2*Sinf+3/4*z3*ln2*Sinf+3/8*z3*
         ln2^2-15/8*z5+1/12*ln2^4*Sinf+1/60*ln2^5+2*Sinf*li4half-2*
         li5half;
Fill Stab5(1,-1,0,0,1) = -13/16*z2*z3+1/6*z2*ln2^3-49/40*z2^2*
         ln2-19/40*z2^2*Sinf+3/4*z3*ln2*Sinf+3/8*z3*ln2^2+47/8*z5-2*
         ln2*li4half-1/20*ln2^5-4*li5half;
Fill Stab5(1,-1,0,1,-1) = 21/16*z2*z3-1/2*z2*ln2^2*Sinf-1/4*z2*
         ln2^3+21/20*z2^2*ln2+5/4*z2^2*Sinf-1/4*z3*ln2*Sinf+19/16*z3*
         ln2^2-61/8*z5-1/6*ln2^4*Sinf-1/20*ln2^5-4*Sinf*li4half+6*
         li5half;
Fill Stab5(1,-1,0,1,1) = -21/16*z2*z3+1/4*z2*ln2^2*Sinf-5/12*z2
         *ln2^3+1/20*z2^2*ln2-1/40*z2^2*Sinf-1/4*z3*ln2*Sinf+19/16*z3*
         ln2^2-85/64*z5+3*ln2*li4half-1/24*ln2^4*Sinf+11/120*ln2^5-
         Sinf*li4half+4*li5half;
Fill Stab5(1,-1,1,-1,-1) = -1/4*z2*ln2^2*Sinf-1/4*z2*ln2^3-3/40
         *z2^2*ln2-1/8*z2^2*Sinf-1/8*z3*ln2*Sinf-1/16*z3*ln2^2+3/64*z5
         +1/24*ln2^4*Sinf+1/30*ln2^5;
Fill Stab5(1,-1,1,-1,1) = -1/4*z2*ln2^2*Sinf-1/4*z2*ln2^3+17/40
         *z2^2*ln2+3/8*z2^2*Sinf-1/8*z3*ln2*Sinf-1/16*z3*ln2^2-29/64*
         z5+1/24*ln2^4*Sinf+1/30*ln2^5;
Fill Stab5(1,-1,1,0,-1) = 1/8*z2*z3-1/12*z2*ln2^3-3/4*z2^2*ln2-
         1/5*z2^2*Sinf+1/8*z3*ln2*Sinf+1/16*z3*ln2^2+123/32*z5+1/12*
         ln2^4*Sinf+1/24*ln2^5+2*Sinf*li4half-5*li5half;
Fill Stab5(1,-1,1,0,1) = -1/16*z2*z3+1/4*z2*ln2^3-37/40*z2^2*
         ln2-1/20*z2^2*Sinf+1/8*z3*ln2*Sinf+1/16*z3*ln2^2+277/64*z5-
         3*ln2*li4half-1/24*ln2^4*Sinf-11/120*ln2^5-Sinf*li4half-4*
         li5half;
Fill Stab5(1,-1,1,1,-1) = 1/2*z2*z3-1/6*z2*ln2^3+7/20*z2^2*ln2+
         2/5*z2^2*Sinf+1/2*z3*ln2^2-63/32*z5+1/40*ln2^5-Sinf*li4half
         +li5half;
Fill Stab5(1,-1,1,1,1) = -1/2*z2*z3-1/6*z2*ln2^3-1/20*z2^2*ln2
         +1/2*z3*ln2^2+1/32*z5+1/40*ln2^5-Sinf*li4half+li5half;
Fill Stab5(1,0,-1,-1,-1) = -1/2*z2*ln2^2*Sinf+1/2*z2*ln2^3+53/
         40*z2^2*ln2+7/5*z2^2*Sinf-21/8*z3*ln2*Sinf-21/16*z3*ln2^2-99/
         32*z5-ln2*li4half-1/6*ln2^4*Sinf-1/15*ln2^5-4*Sinf*li4half+
         3*li5half;
Fill Stab5(1,0,-1,-1,1) = 1/12*z2*ln2^3-43/40*z2^2*ln2+39/40*z2^2
         *Sinf+81/64*z5-1/8*ln2^4*Sinf-1/120*ln2^5-3*Sinf*li4half+
         li5half;
Fill Stab5(1,0,-1,0,-1) = -5/8*z2*z3+13/40*z2^2*Sinf+41/32*z5;
Fill Stab5(1,0,-1,0,1) = 5/16*z2*z3+z2*ln2^2*Sinf+2/3*z2*ln2^3+
         51/40*z2^2*Sinf-7/2*z3*ln2*Sinf-7/4*z3*ln2^2+103/32*z5-4*ln2*
         li4half-1/6*ln2^4*Sinf-2/15*ln2^5-4*Sinf*li4half-4*li5half;
Fill Stab5(1,0,-1,1,-1) = 3/4*z2*ln2^2*Sinf-1/12*z2*ln2^3-1/20*
         z2^2*ln2+3/40*z2^2*Sinf+25/32*z5+1/120*ln2^5-li5half;
Fill Stab5(1,0,-1,1,1) = 1/4*z2*ln2^2*Sinf+1/6*z2*ln2^3+1/8*z2^2*
         Sinf-7/8*z3*ln2*Sinf-7/16*z3*ln2^2+25/32*z5-ln2*li4half-1/
         24*ln2^4*Sinf-1/30*ln2^5-Sinf*li4half-li5half;
Fill Stab5(1,0,0,-1,-1) = 7/8*z2*z3+1/2*z2*ln2^2*Sinf-1/6*z2*
         ln2^3-17/20*z2^2*ln2+3/5*z2^2*Sinf+7/8*z3*ln2^2+15/32*z5-1/
         12*ln2^4*Sinf+1/60*ln2^5-2*Sinf*li4half-2*li5half;
Fill Stab5(1,0,0,-1,1) = -7/8*z2*z3-1/2*z2*ln2^2*Sinf-2/3*z2*
         ln2^3-11/10*z2^2*Sinf+7/4*z3*ln2*Sinf+7/4*z3*ln2^2-39/16*z5
         +4*ln2*li4half+1/12*ln2^4*Sinf+2/15*ln2^5+2*Sinf*li4half+4*
         li5half;
Fill Stab5(1,0,0,0,-1) = -1/2*z2*z3-7/20*z2^2*Sinf+29/32*z5;
Fill Stab5(1,0,0,0,1) = z2*z3+2/5*z2^2*Sinf-2*z5;
Fill Stab5(1,0,0,1,-1) = 1/6*z2*ln2^3+17/20*z2^2*ln2+1/8*z2^2*
         Sinf-7/4*z3*ln2*Sinf-7/8*z3*ln2^2-125/64*z5-1/60*ln2^5+2*
         li5half;
Fill Stab5(1,0,0,1,1) = 1/2*z2^2*Sinf-1/2*z5;
Fill Stab5(1,0,1,-1,-1) = 7/8*z2*z3+5/4*z2*ln2^2*Sinf-1/3*z2*
         ln2^3-53/40*z2^2*ln2+1/40*z2^2*Sinf+7/8*z3*ln2^2+81/64*z5+1/
         24*ln2^4*Sinf+1/30*ln2^5+Sinf*li4half-4*li5half;
Fill Stab5(1,0,1,-1,1) = -7/8*z2*z3-1/4*z2*ln2^2*Sinf-3/4*z2*
         ln2^3-51/40*z2^2*ln2-2*z2^2*Sinf+21/8*z3*ln2*Sinf+35/16*z3*
         ln2^2+87/32*z5+3*ln2*li4half+1/6*ln2^4*Sinf+1/8*ln2^5+4*
         Sinf*li4half;
Fill Stab5(1,0,1,0,-1) = -z2*z3-z2*ln2^2*Sinf-2/3*z2*ln2^3-17/
         8*z2^2*Sinf+7/2*z3*ln2*Sinf+7/4*z3*ln2^2-73/64*z5+4*ln2*
         li4half+1/6*ln2^4*Sinf+2/15*ln2^5+4*Sinf*li4half+4*li5half;
Fill Stab5(1,0,1,0,1) = 2*z2*z3+7/10*z2^2*Sinf-11/2*z5;
Fill Stab5(1,0,1,1,-1) = -3/2*z2*ln2^2*Sinf-1/4*z2*ln2^3+12/5*
         z2^2*ln2-6/5*z2^2*Sinf+7/8*z3*ln2*Sinf+7/16*z3*ln2^2-6*z5+3
         *ln2*li4half+1/8*ln2^4*Sinf+3/40*ln2^5+3*Sinf*li4half+6*
         li5half;
Fill Stab5(1,0,1,1,1) = 6/5*z2^2*Sinf-6*z5;
Fill Stab5(1,1,-1,-1,-1) = -1/8*z2*z3-1/4*z2*ln2*Sinf^2+1/4*z2*
         ln2^2*Sinf+19/20*z2^2*ln2+6/5*z2^2*Sinf-2*z3*ln2*Sinf-z3*
         ln2^2-1/8*z3*Sinf^2-4*z5-1/12*ln2^3*Sinf^2-1/4*ln2^4*Sinf-1/
         12*ln2^5-3*Sinf*li4half+4*li5half;
Fill Stab5(1,1,-1,-1,1) = 7/8*z2*z3-1/4*z2*ln2*Sinf^2+1/4*z2*
         ln2^2*Sinf-1/4*z2^2*ln2+7/8*z3*Sinf^2-1/12*ln2^3*Sinf^2-1/4*
         ln2^4*Sinf-1/12*ln2^5-3*Sinf*li4half+4*li5half;
Fill Stab5(1,1,-1,0,-1) = -1/16*z2*z3-1/2*z2*ln2*Sinf^2+1/4*z2*
         ln2^2*Sinf+1/12*z2*ln2^3-7/20*z2^2*ln2+11/20*z2^2*Sinf+13/16*
         z3*Sinf^2-1/32*z5-1/8*ln2^4*Sinf-1/40*ln2^5-3*Sinf*li4half+
         3*li5half;
Fill Stab5(1,1,-1,0,1) = -1/16*z2*z3+1/4*z2*ln2*Sinf^2+3/4*z2*
         ln2^2*Sinf+1/6*z2*ln2^3+61/40*z2^2*ln2+7/8*z2^2*Sinf-21/8*z3*
         ln2*Sinf-21/16*z3*ln2^2-1/2*z3*Sinf^2-39/8*z5+ln2*li4half-1/
         12*ln2^4*Sinf+1/120*ln2^5-2*Sinf*li4half+4*li5half;
Fill Stab5(1,1,-1,1,-1) = -7/16*z2*z3+1/4*z2*ln2*Sinf^2+1/2*z2*
         ln2^2*Sinf+1/4*z2*ln2^3+3/5*z2^2*ln2-1/20*z2^2*Sinf-1/2*z3*
         ln2^2+1/16*z3*Sinf^2+1/32*z5-1/12*ln2^3*Sinf^2-1/8*ln2^4*Sinf
         -7/120*ln2^5+li5half;
Fill Stab5(1,1,-1,1,1) = 1/16*z2*z3+1/4*z2*ln2*Sinf^2+1/2*z2*
         ln2^2*Sinf+1/4*z2*ln2^3+7/10*z2^2*ln2+1/20*z2^2*Sinf-z3*ln2*
         Sinf-z3*ln2^2-7/16*z3*Sinf^2-63/32*z5-1/12*ln2^3*Sinf^2-1/8
         *ln2^4*Sinf-7/120*ln2^5+li5half;
Fill Stab5(1,1,0,-1,-1) = -3/4*z2*z3+3/4*z2*ln2*Sinf^2-1/4*z2*
         ln2^2*Sinf+1/12*z2*ln2^3+31/20*z2^2*ln2-1/8*z2^2*Sinf-7/16*z3
         *ln2^2-5/16*z3*Sinf^2-27/32*z5+1/24*ln2^4*Sinf-1/120*ln2^5+
         Sinf*li4half+li5half;
Fill Stab5(1,1,0,-1,1) = 1/8*z2*z3+1/6*z2*ln2^3-3/40*z2^2*Sinf-
         7/16*z3*ln2^2-5/16*z3*Sinf^2+1/8*z5-ln2*li4half-1/30*ln2^5-
         li5half;
Fill Stab5(1,1,0,0,-1) = 1/8*z2*z3+1/2*z2*ln2^2*Sinf+1/3*z2*ln2^3
         +3/4*z2^2*Sinf-7/4*z3*ln2*Sinf-7/8*z3*ln2^2-3/8*z3*Sinf^2+
         33/32*z5-2*ln2*li4half-1/12*ln2^4*Sinf-1/15*ln2^5-2*Sinf*
         li4half-2*li5half;
Fill Stab5(1,1,0,0,1) = -1/2*z2*z3-1/10*z2^2*Sinf+1/2*z3*Sinf^2
         +2*z5;
Fill Stab5(1,1,0,1,-1) = 1/8*z2*z3-3/4*z2*ln2*Sinf^2+3/4*z2*ln2^2
         *Sinf+5/12*z2*ln2^3-31/20*z2^2*ln2+6/5*z2^2*Sinf-7/4*z3*ln2*
         Sinf-7/8*z3*ln2^2+1/8*z3*Sinf^2+4*z5-3*ln2*li4half-1/8*
         ln2^4*Sinf-11/120*ln2^5-3*Sinf*li4half-4*li5half;
Fill Stab5(1,1,0,1,1) = z2*z3-6/5*z2^2*Sinf+z3*Sinf^2+4*z5;
Fill Stab5(1,1,1,-1,-1) = -13/48*z2*z3+1/4*z2*ln2*Sinf^2+1/4*z2
         *ln2^2*Sinf+1/6*z2*ln2^3+1/12*z2*Sinf^3+1/4*z2^2*ln2+1/4*z2^2
         *Sinf+1/6*z3*ln2^2-7/16*z3*Sinf^2+1/12*ln2^2*Sinf^3+1/6*ln2^3
         *Sinf^2+1/6*ln2^4*Sinf+1/24*ln2^5+Sinf*li4half-li5half;
Fill Stab5(1,1,1,-1,1) = -5/48*z2*z3-1/4*z2*ln2*Sinf^2-1/4*z2*
         ln2^2*Sinf-1/12*z2*Sinf^3-13/20*z2^2*ln2-13/20*z2^2*Sinf+z3*
         ln2*Sinf+2/3*z3*ln2^2+1/16*z3*Sinf^2+z5+1/12*ln2^2*Sinf^3+1/
         6*ln2^3*Sinf^2+1/6*ln2^4*Sinf+1/24*ln2^5+Sinf*li4half-li5half
         ;
Fill Stab5(1,1,1,0,-1) = -11/48*z2*z3-1/4*z2*ln2^2*Sinf-1/6*z2*
         ln2^3-1/12*z2*Sinf^3-13/20*z2^2*Sinf+7/8*z3*ln2*Sinf+7/16*z3*
         ln2^2-1/16*z3*Sinf^2-z5+ln2*li4half+1/24*ln2^4*Sinf+1/30*
         ln2^5+Sinf*li4half+li5half;
Fill Stab5(1,1,1,0,1) = -1/6*z2*z3+1/6*z2*Sinf^3+9/10*z2^2*Sinf
         -1/2*z3*Sinf^2-z5;
Fill Stab5(1,1,1,1,-1) = -1/4*z2*ln2*Sinf^2-1/4*z2*ln2^2*Sinf-1/
         12*z2*ln2^3-9/40*z2^2*ln2-1/3*z3*ln2*Sinf-1/6*z3*ln2^2-1/24*
         ln2*Sinf^4-1/12*ln2^2*Sinf^3-1/12*ln2^3*Sinf^2-1/24*ln2^4*Sinf
         -1/120*ln2^5;
Fill Stab5(1,1,1,1,1) = 1/6*z2*z3+1/12*z2*Sinf^3+9/40*z2^2*Sinf
         +1/6*z3*Sinf^2+1/5*z5+1/120*Sinf^5;
#endprocedure
*
*--#] table5 : 
*--#[ table6 :
*
#procedure table6
*
*   New constants: li6half = Li_6(1/2) = -S(R(-1,1,1,1,1,1),inf)
*                  s6 = S(R(-5,-1),inf)
*                     = int(dx,0,1,Li(5,x)/x/(1+x))
*   File by J. Vermaseren, 5-jun-1998
*
S   li6half,s6;
CTable,relax,Stab6(-1:1,-1:1,-1:1,-1:1,-1:1,-1:1);
Fill Stab6(-1,-1,-1,-1,-1,-1) =1/8*z2*z3*ln2+1/48*z2*ln2^4+9/80*
         z2^2*ln2^2+61/560*z2^3+1/24*z3*ln2^3+1/32*z3^2+3/16*z5*ln2+
         1/720*ln2^6;
Fill Stab6(-1,-1,-1,-1,-1,1) =1/8*z2*z3*ln2+1/48*z2*ln2^4+9/80*
         z2^2*ln2^2-187/560*z2^3+1/24*z3*ln2^3+1/32*z3^2+3/16*z5*ln2
         +1/720*ln2^6;
Fill Stab6(-1,-1,-1,-1,0,-1) =3/8*z2*z3*ln2-1/48*z2*ln2^4-3/10*
         z2^2*ln2^2-57/112*z2^3+1/6*z3*ln2^3+1/4*z3^2+z5*ln2;
Fill Stab6(-1,-1,-1,-1,0,1) =3/4*z2*z3*ln2-1/48*z2*ln2^4-3/16*
         z2^2*ln2^2-99/280*z2^3+1/6*z3*ln2^3+13/64*z3^2+z5*ln2+1/240
         *ln2^6+3*li6half-3/4*s6;
Fill Stab6(-1,-1,-1,-1,1,-1) =23/16*z2*z3*ln2-5/48*z2*ln2^4+3/2*
         z2*li4half-21/80*z2^2*ln2^2-11/7*z2^3+23/48*z3*ln2^3+41/64*
         z3^2-23/64*z5*ln2+3*ln2*li5half+3/2*ln2^2*li4half+31/720*
         ln2^6+3*li6half-3/4*s6;
Fill Stab6(-1,-1,-1,-1,1,1) =23/16*z2*z3*ln2-5/48*z2*ln2^4+3/2*
         z2*li4half-21/80*z2^2*ln2^2-3/7*z2^3+23/48*z3*ln2^3-87/64*
         z3^2-23/64*z5*ln2+3*ln2*li5half+3/2*ln2^2*li4half+31/720*
         ln2^6+3*li6half-3/4*s6;
Fill Stab6(-1,-1,-1,0,-1,-1) =2*z2*z3*ln2-1/12*z2*ln2^4+2*z2*
         li4half-39/40*z2^2*ln2^2-249/70*z2^3+13/24*z3*ln2^3-9/8*z3^2
         -101/64*z5*ln2+5*ln2*li5half+2*ln2^2*li4half+23/360*ln2^6+
         16*li6half+4*s6;
Fill Stab6(-1,-1,-1,0,-1,1) =13/8*z2*z3*ln2-3/16*z2*ln2^4+2*z2*
         li4half-49/80*z2^2*ln2^2-65/56*z2^3+13/24*z3*ln2^3-25/8*z3^2
         -101/64*z5*ln2+5*ln2*li5half+2*ln2^2*li4half+13/240*ln2^6+9
         *li6half+7/4*s6;
Fill Stab6(-1,-1,-1,0,0,-1) =11/8*z2*z3*ln2-1/24*z2*ln2^4-1/10*
         z2^2*ln2^2-123/560*z2^3+1/8*z3*ln2^3+15/8*z5*ln2+1/360*ln2^6
         +2*li6half-9/4*s6;
Fill Stab6(-1,-1,-1,0,0,1) =-1/8*z2*z3*ln2-19/80*z2^2*ln2^2-71/
         112*z2^3+1/8*z3*ln2^3+11/16*z3^2+15/8*z5*ln2;
Fill Stab6(-1,-1,-1,0,1,-1) =-1/2*z2*z3*ln2-1/24*z2*ln2^4-2*z2
         *li4half+9/10*z2^2*ln2^2+487/140*z2^3-1/24*z3*ln2^3+243/64*
         z3^2+61/8*z5*ln2-8*ln2*li5half-2*ln2^2*li4half-17/360*ln2^6
         -22*li6half-10*s6;
Fill Stab6(-1,-1,-1,0,1,1) =-1/8*z2*z3*ln2+7/48*z2*ln2^4+z2*
         li4half-21/80*z2^2*ln2^2+163/140*z2^3-1/24*z3*ln2^3+117/64*
         z3^2+61/8*z5*ln2-8*ln2*li5half-2*ln2^2*li4half-5/144*ln2^6-
         13*li6half-19/4*s6;
Fill Stab6(-1,-1,-1,1,-1,-1) =23/16*z2*z3*ln2-5/48*z2*ln2^4-19/
         80*z2^2*ln2^2-11/80*z2^3+23/48*z3*ln2^3+167/64*z3^2+369/64*z5
         *ln2-3*ln2*li5half+13/720*ln2^6-6*li6half-6*s6;
Fill Stab6(-1,-1,-1,1,-1,1) =23/16*z2*z3*ln2-5/48*z2*ln2^4-19/80
         *z2^2*ln2^2+2089/1680*z2^3+23/48*z3*ln2^3-25/64*z3^2+369/64*
         z5*ln2-3*ln2*li5half+13/720*ln2^6-6*li6half-6*s6;
Fill Stab6(-1,-1,-1,1,0,-1) =47/16*z2*z3*ln2+7/48*z2*ln2^4+5/2*
         z2*li4half-13/16*z2^2*ln2^2-41/56*z2^3+1/48*z3*ln2^3-189/128*
         z3^2+125/32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-7/720*ln2^6
         +2*li6half-9/4*s6;
Fill Stab6(-1,-1,-1,1,0,1) =-11/8*z2*z3*ln2-1/24*z2*ln2^4-2*z2
         *li4half+1/5*z2^2*ln2^2-7/40*z2^3+1/48*z3*ln2^3+129/64*z3^2
         +125/32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-1/72*ln2^6-
         li6half-3/2*s6;
Fill Stab6(-1,-1,-1,1,1,-1) =-z2*z3*ln2-1/16*z2*ln2^4-1/2*z2*
         li4half-9/80*z2^2*ln2^2+143/105*z2^3+1/3*z3*ln2^3+23/32*z3^2
         +4*z5*ln2-4*ln2*li5half-1/2*ln2^2*li4half+1/240*ln2^6-7*
         li6half-9/4*s6;
Fill Stab6(-1,-1,-1,1,1,1) =-z2*z3*ln2-1/16*z2*ln2^4-1/2*z2*
         li4half-9/80*z2^2*ln2^2+23/35*z2^3+1/3*z3*ln2^3+55/32*z3^2+
         4*z5*ln2-4*ln2*li5half-1/2*ln2^2*li4half+1/240*ln2^6-7*
         li6half-9/4*s6;
Fill Stab6(-1,-1,0,-1,-1,-1) =-5/12*z2*ln2^4-2*z2*li4half+29/8
         *z2^2*ln2^2+421/70*z2^3+39/4*z3^2+911/64*z5*ln2-13*ln2*
         li5half-2*ln2^2*li4half-1/24*ln2^6-48*li6half-26*s6;
Fill Stab6(-1,-1,0,-1,-1,1) =21/16*z2*z3*ln2-1/6*z2*ln2^4-2*z2*
         li4half+47/20*z2^2*ln2^2+1737/280*z2^3+7/16*z3*ln2^3+417/64*
         z3^2+911/64*z5*ln2-13*ln2*li5half-2*ln2^2*li4half-1/30*ln2^6
         -42*li6half-47/2*s6;
Fill Stab6(-1,-1,0,-1,0,-1) =13/4*z2*z3*ln2+1/6*z2*ln2^4+2*z2*
         li4half-27/80*z2^2*ln2^2+281/240*z2^3+59/64*z3^2+331/32*z5*
         ln2-8*ln2*li5half-2*ln2^2*li4half-1/30*ln2^6-12*li6half-19/
         2*s6;
Fill Stab6(-1,-1,0,-1,0,1) =-27/8*z2*z3*ln2-4*z2*li4half+131/
         80*z2^2*ln2^2+4307/1680*z2^3-7/12*z3*ln2^3+73/16*z3^2+331/32*
         z5*ln2-8*ln2*li5half-2*ln2^2*li4half-7/180*ln2^6-16*li6half
         -9*s6;
Fill Stab6(-1,-1,0,-1,1,-1) =-21/16*z2*z3*ln2+1/16*z2*ln2^4-9/
         8*z2^2*ln2^2+2/35*z2^3+7/16*z3*ln2^3-165/128*z3^2+99/32*z5*
         ln2-3*ln2*li5half+7/240*ln2^6+3*li6half+3*s6;
Fill Stab6(-1,-1,0,-1,1,1) =-7/4*z2*z3*ln2-7/48*z2*ln2^4-z2*
         li4half+5/16*z2^2*ln2^2+233/280*z2^3+7/24*z3*ln2^3+241/128*
         z3^2+99/32*z5*ln2-3*ln2*li5half+11/720*ln2^6-7*li6half-9/4*
         s6;
Fill Stab6(-1,-1,0,0,-1,-1) =-3/2*z2*z3*ln2+1/8*z2*ln2^4+1/40*
         z2^2*ln2^2+2113/1680*z2^3+1/32*z3^2-15/32*z5*ln2-1/120*ln2^6
         -6*li6half+3/4*s6;
Fill Stab6(-1,-1,0,0,-1,1) =7/8*z2*z3*ln2+1/24*z2*ln2^4+2*z2*
         li4half-21/20*z2^2*ln2^2-403/336*z2^3+7/24*z3*ln2^3-1/2*z3^2
         -15/32*z5*ln2+1/360*ln2^6+2*li6half+11/4*s6;
Fill Stab6(-1,-1,0,0,0,-1) =-3/8*z2*z3*ln2-7/40*z2^2*ln2^2-71/
         112*z2^3+3/4*z3^2+2*z5*ln2;
Fill Stab6(-1,-1,0,0,0,1) =3/4*z2*z3*ln2+1/5*z2^2*ln2^2+17/70*
         z2^3-11/64*z3^2+2*z5*ln2-5/2*s6;
Fill Stab6(-1,-1,0,0,1,-1) =3/2*z2*z3*ln2-1/6*z2*ln2^4+27/80*
         z2^2*ln2^2-295/336*z2^3+7/4*z3^2+311/64*z5*ln2-2*ln2*li5half
         +1/60*ln2^6-5*s6;
Fill Stab6(-1,-1,0,0,1,1) =7/8*z2*z3*ln2-1/12*z2*ln2^4+1/4*z2^2*
         ln2^2+1801/1680*z2^3+7/24*z3*ln2^3-9/16*z3^2+311/64*z5*ln2-
         2*ln2*li5half+1/90*ln2^6-4*li6half-21/4*s6;
Fill Stab6(-1,-1,0,1,-1,-1) =17/48*z2*ln2^4+7/2*z2*li4half-263/
         80*z2^2*ln2^2-3643/560*z2^3-39/4*z3^2-245/16*z5*ln2+16*ln2*
         li5half+7/2*ln2^2*li4half+19/240*ln2^6+48*li6half+26*s6;
Fill Stab6(-1,-1,0,1,-1,1) =21/16*z2*z3*ln2-1/48*z2*ln2^4+1/2*z2
         *li4half-191/80*z2^2*ln2^2-3331/560*z2^3+7/16*z3*ln2^3-459/64
         *z3^2-245/16*z5*ln2+16*ln2*li5half+7/2*ln2^2*li4half+17/240*
         ln2^6+42*li6half+20*s6;
Fill Stab6(-1,-1,0,1,0,-1) =15/8*z2*z3*ln2-1/16*z2*ln2^4+5/2*z2*
         li4half-27/16*z2^2*ln2^2-1381/420*z2^3+7/12*z3*ln2^3-49/16*
         z3^2-227/32*z5*ln2+8*ln2*li5half+2*ln2^2*li4half+7/180*ln2^6
         +16*li6half+9*s6;
Fill Stab6(-1,-1,0,1,0,1) =-1/4*z2*z3*ln2-1/24*z2*ln2^4+z2*
         li4half+1/10*z2^2*ln2^2-491/336*z2^3-125/64*z3^2-227/32*z5*
         ln2+8*ln2*li5half+2*ln2^2*li4half+1/30*ln2^6+12*li6half+23/
         4*s6;
Fill Stab6(-1,-1,0,1,1,-1) =21/16*z2*z3*ln2-5/12*z2*ln2^4+3/2*z2
         *li4half+7/80*z2^2*ln2^2-11/7*z2^3+7/16*z3*ln2^3+39/64*z3^2
         -81/64*z5*ln2+4*ln2*li5half+3/2*ln2^2*li4half+1/30*ln2^6+3*
         li6half-3/4*s6;
Fill Stab6(-1,-1,0,1,1,1) =7/8*z2*z3*ln2-1/12*z2*ln2^4+3/2*z2*
         li4half+9/40*z2^2*ln2^2-3/5*z2^3+7/24*z3*ln2^3-49/32*z3^2-
         81/64*z5*ln2+4*ln2*li5half+3/2*ln2^2*li4half+13/360*ln2^6+5*
         li6half;
Fill Stab6(-1,-1,1,-1,-1,-1) =-7/8*z2*z3*ln2+1/12*z2*ln2^4-3/2
         *z2*li4half-9/40*z2^2*ln2^2+3/5*z2^3-7/24*z3*ln2^3-15/32*z3^2
         +81/64*z5*ln2-3*ln2*li5half-3/2*ln2^2*li4half-13/360*ln2^6;
Fill Stab6(-1,-1,1,-1,-1,1) =-7/8*z2*z3*ln2+1/12*z2*ln2^4-3/2*
         z2*li4half-9/40*z2^2*ln2^2+3/5*z2^3-7/24*z3*ln2^3+49/32*z3^2
         +81/64*z5*ln2-3*ln2*li5half-3/2*ln2^2*li4half-13/360*ln2^6;
Fill Stab6(-1,-1,1,-1,0,-1) =1/16*z2*z3*ln2+5/48*z2*ln2^4-z2*
         li4half+1/16*z2^2*ln2^2+1/112*z2^3-13/48*z3*ln2^3+115/128*
         z3^2+33/64*z5*ln2-ln2*li5half-ln2^2*li4half-7/240*ln2^6+3*
         li6half-1/2*s6;
Fill Stab6(-1,-1,1,-1,0,1) =-5/4*z2*z3*ln2+5/48*z2*ln2^4-z2*
         li4half-1/20*z2^2*ln2^2+31/70*z2^3-13/48*z3*ln2^3-91/64*z3^2
         +33/64*z5*ln2-ln2*li5half-ln2^2*li4half-1/30*ln2^6+7/4*s6;
Fill Stab6(-1,-1,1,-1,1,-1) =-9/16*z2*z3*ln2-1/24*z2*ln2^4-3/5
         *z2^2*ln2^2-1/56*z2^3+7/48*z3*ln2^3-69/64*z3^2-3/64*z5*ln2+
         1/180*ln2^6+3*li6half+3*s6;
Fill Stab6(-1,-1,1,-1,1,1) =-9/16*z2*z3*ln2-1/24*z2*ln2^4-3/5*
         z2^2*ln2^2-71/168*z2^3+7/48*z3*ln2^3-101/64*z3^2-3/64*z5*ln2
         +1/180*ln2^6+3*li6half+3*s6;
Fill Stab6(-1,-1,1,0,-1,-1) =-z2*z3*ln2-1/12*z2*ln2^4-3/2*z2*
         li4half+31/40*z2^2*ln2^2+1943/560*z2^3+5/48*z3*ln2^3+361/128*
         z3^2+457/64*z5*ln2-7*ln2*li5half-3/2*ln2^2*li4half-1/30*ln2^6
         -21*li6half-33/4*s6;
Fill Stab6(-1,-1,1,0,-1,1) =5/16*z2*z3*ln2+5/48*z2*ln2^4+3/2*z2*
         li4half-31/80*z2^2*ln2^2+443/560*z2^3+5/48*z3*ln2^3+181/128*
         z3^2+457/64*z5*ln2-7*ln2*li5half-3/2*ln2^2*li4half-1/48*ln2^6
         -12*li6half-9/2*s6;
Fill Stab6(-1,-1,1,0,0,-1) =-9/16*z2*z3*ln2+5/48*z2*ln2^4-1/2*
         z2*li4half-9/80*z2^2*ln2^2+8/35*z2^3-1/6*z3*ln2^3-25/64*z3^2
         +151/64*z5*ln2-2*ln2*li5half-ln2^2*li4half-1/36*ln2^6-2*
         li6half-1/4*s6;
Fill Stab6(-1,-1,1,0,0,1) =-3/8*z2*z3*ln2-2*z2*li4half+2/5*
         z2^2*ln2^2+201/280*z2^3-1/6*z3*ln2^3+163/128*z3^2+151/64*z5*
         ln2-2*ln2*li5half-ln2^2*li4half-1/40*ln2^6-5/2*s6;
Fill Stab6(-1,-1,1,0,1,-1) =-1/8*z2*z3*ln2+5/24*z2*ln2^4-3/2*
         z2*li4half-1/10*z2^2*ln2^2-31/35*z2^3-23/48*z3*ln2^3-25/32*
         z3^2+23/64*z5*ln2-2*ln2*li5half-3/2*ln2^2*li4half-1/30*ln2^6
         +9*li6half+3/2*s6;
Fill Stab6(-1,-1,1,0,1,1) =-23/16*z2*z3*ln2+5/48*z2*ln2^4-3/2*
         z2*li4half+21/80*z2^2*ln2^2+3/7*z2^3-23/48*z3*ln2^3+87/64*
         z3^2+23/64*z5*ln2-2*ln2*li5half-3/2*ln2^2*li4half-31/720*
         ln2^6+2*li6half+3/4*s6;
Fill Stab6(-1,-1,1,1,-1,-1) =7/16*z2*z3*ln2-1/24*z2*ln2^4+1/2*z2
         *li4half-1/8*z2^2*ln2^2-18/35*z2^3+7/48*z3*ln2^3-109/64*z3^2
         -27/32*z5*ln2+2*ln2*li5half+1/2*ln2^2*li4half+1/72*ln2^6+6*
         li6half+5/2*s6;
Fill Stab6(-1,-1,1,1,-1,1) =7/16*z2*z3*ln2-1/24*z2*ln2^4+1/2*z2*
         li4half-1/8*z2^2*ln2^2-172/105*z2^3+7/48*z3*ln2^3-45/64*z3^2
         -27/32*z5*ln2+2*ln2*li5half+1/2*ln2^2*li4half+1/72*ln2^6+6*
         li6half+5/2*s6;
Fill Stab6(-1,-1,1,1,0,-1) =1/2*z2*z3*ln2+z2*li4half-11/20*z2^2*
         ln2^2-47/35*z2^3+1/6*z3*ln2^3-3/4*z3^2+1/32*z5*ln2+2*ln2*
         li5half+1/2*ln2^2*li4half+1/120*ln2^6+3*li6half+2*s6;
Fill Stab6(-1,-1,1,1,0,1) =1/2*z2*z3*ln2-1/16*z2*ln2^4-1/2*z2*
         li4half-1/16*z2^2*ln2^2-1/7*z2^3+1/6*z3*ln2^3-25/32*z3^2+1/
         32*z5*ln2+2*ln2*li5half+1/2*ln2^2*li4half+1/80*ln2^6+6*
         li6half-1/4*s6;
Fill Stab6(-1,-1,1,1,1,-1) =-8/7*z2^3+ln2*li5half+5*li6half;
Fill Stab6(-1,-1,1,1,1,1) =ln2*li5half+5*li6half;
Fill Stab6(-1,0,-1,-1,-1,-1) =-15/16*z2*z3*ln2+11/12*z2*ln2^4-
         161/40*z2^2*ln2^2-186/35*z2^3-7/16*z3*ln2^3-333/32*z3^2-845/
         64*z5*ln2+11*ln2*li5half-1/40*ln2^6+48*li6half+26*s6;
Fill Stab6(-1,0,-1,-1,-1,1) =-21/16*z2*z3*ln2+23/48*z2*ln2^4+3/
         2*z2*li4half-271/80*z2^2*ln2^2-3019/560*z2^3-7/16*z3*ln2^3-
         417/64*z3^2-845/64*z5*ln2+11*ln2*li5half+3/2*ln2^2*li4half+7/
         240*ln2^6+42*li6half+47/2*s6;
Fill Stab6(-1,0,-1,-1,0,-1) =-13/8*z2*z3*ln2-1/6*z2*ln2^4+3/8*
         z2^2*ln2^2-13/5*z2^3-455/128*z3^2-547/32*z5*ln2+16*ln2*
         li5half+4*ln2^2*li4half+1/15*ln2^6+24*li6half+13*s6;
Fill Stab6(-1,0,-1,-1,0,1) =37/16*z2*z3*ln2+5/12*z2*ln2^4+2*z2*
         li4half-39/10*z2^2*ln2^2-421/70*z2^3-95/8*z3^2-547/32*z5*ln2
         +16*ln2*li5half-1/15*ln2^6+48*li6half+26*s6;
Fill Stab6(-1,0,-1,-1,1,-1) =1/12*z2*ln2^4-17/8*z2^2*ln2^2-107/
         40*z2^3-39/8*z3^2-221/32*z5*ln2+7*ln2*li5half-1/40*ln2^6+24
         *li6half+13*s6;
Fill Stab6(-1,0,-1,-1,1,1) =21/16*z2*z3*ln2+17/48*z2*ln2^4+1/2*
         z2*li4half-47/16*z2^2*ln2^2-2141/560*z2^3-891/128*z3^2-221/32
         *z5*ln2+7*ln2*li5half-1/2*ln2^2*li4half-3/80*ln2^6+30*li6half
         +31/2*s6;
Fill Stab6(-1,0,-1,0,-1,-1) =-15/16*z2*z3*ln2+1/6*z2*ln2^4-4*
         z2*li4half-73/40*z2^2*ln2^2+183/140*z2^3+25/128*z3^2+123/16*
         z5*ln2-8*ln2*li5half-4*ln2^2*li4half-1/10*ln2^6;
Fill Stab6(-1,0,-1,0,-1,1) =15/16*z2*z3*ln2+1/6*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2+45/56*z2^3+17/16*z3^2+123/16*z5*ln2-
         8*ln2*li5half-2*ln2^2*li4half-1/30*ln2^6-12*li6half-9/2*s6;
Fill Stab6(-1,0,-1,0,0,-1) =15/8*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-853/1680*z2^3-15/8*z3^2-21/32*z5*ln2
         +s6;
Fill Stab6(-1,0,-1,0,0,1) =-3/2*z2*z3*ln2-1/6*z2*ln2^4-4*z2*
         li4half+z2^2*ln2^2+503/420*z2^3+59/32*z3^2-21/32*z5*ln2-5/2
         *s6;
Fill Stab6(-1,0,-1,0,1,-1) =-19/16*z2*z3*ln2+113/40*z2^2*ln2^2
         +76/35*z2^3-7/12*z3*ln2^3+45/16*z3^2+89/64*z5*ln2-4*ln2*
         li5half+1/90*ln2^6-16*li6half-8*s6;
Fill Stab6(-1,0,-1,0,1,1) =-7/4*z2*z3*ln2+1/6*z2*ln2^4-2*z2*
         li4half+1/2*z2^2*ln2^2+589/560*z2^3-7/12*z3*ln2^3+99/32*z3^2
         +89/64*z5*ln2-4*ln2*li5half-2*ln2^2*li4half-1/18*ln2^6-4*
         li6half-7/4*s6;
Fill Stab6(-1,0,-1,1,-1,-1) =-29/48*z2*ln2^4-2*z2*li4half+19/
         16*z2^2*ln2^2+97/40*z2^3+111/32*z3^2+457/64*z5*ln2-7*ln2*
         li5half-2*ln2^2*li4half-11/240*ln2^6-15*li6half-37/4*s6;
Fill Stab6(-1,0,-1,1,-1,1) =-3/16*z2*z3*ln2-1/2*z2*ln2^4+1/2*
         z2*li4half+39/20*z2^2*ln2^2+2*z2^3+501/128*z3^2+457/64*z5*ln2
         -7*ln2*li5half-1/2*ln2^2*li4half+1/120*ln2^6-21*li6half-10*
         s6;
Fill Stab6(-1,0,-1,1,0,-1) =1/8*z2*z3*ln2+1/48*z2*ln2^4+1/2*z2*
         li4half-1/8*z2^2*ln2^2-279/560*z2^3-61/128*z3^2+53/64*z5*ln2
         +s6;
Fill Stab6(-1,0,-1,1,0,1) =1/8*z2*z3*ln2-1/24*z2*ln2^4-z2*
         li4half+1/4*z2^2*ln2^2+261/560*z2^3+119/128*z3^2+53/64*z5*ln2
         -11/4*s6;
Fill Stab6(-1,0,-1,1,1,-1) =-7/16*z2*z3*ln2+5/16*z2*ln2^4+29/
         16*z2^2*ln2^2+22/35*z2^3-7/48*z3*ln2^3+107/64*z3^2+27/32*z5*
         ln2-ln2*li5half-1/720*ln2^6-7*li6half-19/4*s6;
Fill Stab6(-1,0,-1,1,1,1) =-7/16*z2*z3*ln2+1/24*z2*ln2^4-1/2*
         z2*li4half+1/8*z2^2*ln2^2+18/35*z2^3-7/48*z3*ln2^3+109/64*
         z3^2+27/32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-1/72*ln2^6-
         li6half-5/2*s6;
Fill Stab6(-1,0,0,-1,-1,-1) =-z2*z3*ln2-1/3*z2*ln2^4+z2*
         li4half-9/20*z2^2*ln2^2-509/560*z2^3-25/32*z3^2-15/32*z5*ln2
         +ln2^2*li4half+1/20*ln2^6+6*li6half+17/4*s6;
Fill Stab6(-1,0,0,-1,-1,1) =-13/16*z2*z3*ln2-11/24*z2*ln2^4-2*
         z2*li4half+149/80*z2^2*ln2^2+27/35*z2^3+77/32*z3^2-15/32*z5*
         ln2+2*ln2^2*li4half+3/40*ln2^6-6*li6half-17/4*s6;
Fill Stab6(-1,0,0,-1,0,-1) =-9/8*z2*z3*ln2-1/24*z2*ln2^4-z2*
         li4half+1/4*z2^2*ln2^2-89/840*z2^3+3/4*z3^2-11/32*z5*ln2+s6;
Fill Stab6(-1,0,0,-1,0,1) =-5/4*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-179/840*z2^3+5/64*z3^2-11/32*z5*ln2+
         5/2*s6;
Fill Stab6(-1,0,0,-1,1,-1) =15/16*z2*z3*ln2+1/8*z2*ln2^4+19/80*
         z2^2*ln2^2-4/5*z2^3+7/24*z3*ln2^3+5/8*z3^2-15/32*z5*ln2+2*
         ln2*li5half-1/72*ln2^6+2*li6half-5/4*s6;
Fill Stab6(-1,0,0,-1,1,1) =-1/8*z2*z3*ln2-1/12*z2*ln2^4+z2*
         li4half-1/4*z2^2*ln2^2-29/280*z2^3+7/24*z3*ln2^3-29/32*z3^2
         -15/32*z5*ln2+2*ln2*li5half+ln2^2*li4half+1/36*ln2^6+2*
         li6half+1/2*s6;
Fill Stab6(-1,0,0,0,-1,-1) =3/2*z2*z3*ln2+3/4*z2^2*ln2^2-491/840
         *z2^3+33/32*z3^2+59/32*z5*ln2-4*s6;
Fill Stab6(-1,0,0,0,-1,1) =z2*z3*ln2+53/168*z2^3-5/8*z3^2+59/
         32*z5*ln2-5/2*s6;
Fill Stab6(-1,0,0,0,0,-1) =8/35*z2^3+15/16*z5*ln2-s6;
Fill Stab6(-1,0,0,0,0,1) =-111/280*z2^3+9/32*z3^2+15/16*z5*ln2;
Fill Stab6(-1,0,0,0,1,-1) =-15/8*z2*z3*ln2-3/4*z2^2*ln2^2+47/
         105*z2^3-21/32*z3^2-17/16*z5*ln2+4*s6;
Fill Stab6(-1,0,0,0,1,1) =-1/2*z2*z3*ln2-179/840*z2^3+11/64*
         z3^2-17/16*z5*ln2+3/2*s6;
Fill Stab6(-1,0,0,1,-1,-1) =1/2*z2*z3*ln2+1/3*z2*ln2^4+1/5*z2^2*
         ln2^2-1/2*z3^2-27/8*z5*ln2+4*ln2*li5half-1/30*ln2^6;
Fill Stab6(-1,0,0,1,-1,1) =13/8*z2*z3*ln2+1/8*z2*ln2^4+z2*
         li4half-23/80*z2^2*ln2^2+11/80*z2^3-169/128*z3^2-27/8*z5*ln2
         +4*ln2*li5half+ln2^2*li4half+1/120*ln2^6;
Fill Stab6(-1,0,0,1,0,-1) =9/4*z2*z3*ln2+121/840*z2^3-33/64*z3^2
         +51/32*z5*ln2-7/2*s6;
Fill Stab6(-1,0,0,1,0,1) =5/8*z2*z3*ln2-493/1680*z2^3-1/4*z3^2
         +51/32*z5*ln2-s6;
Fill Stab6(-1,0,0,1,1,-1) =-z2*z3*ln2-1/8*z2*ln2^4-z2*li4half
         -21/16*z2^2*ln2^2-247/560*z2^3+7/24*z3*ln2^3-217/128*z3^2+
         125/64*z5*ln2-2*ln2*li5half-ln2^2*li4half-1/72*ln2^6+8*
         li6half+9/2*s6;
Fill Stab6(-1,0,0,1,1,1) =-3/8*z2*z3*ln2-1/12*z2*ln2^4+23/80*
         z2^3+7/24*z3*ln2^3+47/64*z3^2+125/64*z5*ln2-2*ln2*li5half+1/
         90*ln2^6-4*li6half-5/4*s6;
Fill Stab6(-1,0,1,-1,-1,-1) =-3/8*z2*z3*ln2-19/24*z2*ln2^4+161/
         40*z2^2*ln2^2+1459/280*z2^3+501/64*z3^2+61/8*z5*ln2-8*ln2*
         li5half+1/120*ln2^6-42*li6half-20*s6;
Fill Stab6(-1,0,1,-1,-1,1) =-41/48*z2*ln2^4-3/2*z2*li4half+463/
         80*z2^2*ln2^2+3293/560*z2^3+39/4*z3^2+61/8*z5*ln2-8*ln2*
         li5half+3/2*ln2^2*li4half+1/16*ln2^6-48*li6half-26*s6;
Fill Stab6(-1,0,1,-1,0,-1) =-1/2*z2*z3*ln2-5/12*z2*ln2^4-2*z2*
         li4half+39/10*z2^2*ln2^2+1643/280*z2^3+41/4*z3^2+507/32*z5*
         ln2-16*ln2*li5half+1/15*ln2^6-48*li6half-26*s6;
Fill Stab6(-1,0,1,-1,0,1) =-1/2*z2*z3*ln2+1/6*z2*ln2^4-3/8*
         z2^2*ln2^2+213/70*z2^3+77/16*z3^2+507/32*z5*ln2-16*ln2*
         li5half-4*ln2^2*li4half-1/15*ln2^6-24*li6half-23/2*s6;
Fill Stab6(-1,0,1,-1,1,-1) =21/16*z2*z3*ln2+1/8*z2*ln2^4+93/40*
         z2^2*ln2^2+3*z2^3+7/16*z3*ln2^3+441/64*z3^2+61/8*z5*ln2-6*
         ln2*li5half+1/120*ln2^6-30*li6half-35/2*s6;
Fill Stab6(-1,0,1,-1,1,1) =-7/48*z2*ln2^4-1/2*z2*li4half+51/80
         *z2^2*ln2^2+1991/560*z2^3+7/16*z3*ln2^3+405/128*z3^2+61/8*z5*
         ln2-6*ln2*li5half-1/2*ln2^2*li4half-1/240*ln2^6-24*li6half-
         23/2*s6;
Fill Stab6(-1,0,1,0,-1,-1) =11/8*z2*z3*ln2-19/20*z2^2*ln2^2-20/7
         *z2^3+7/12*z3*ln2^3-33/32*z3^2-33/32*z5*ln2+4*ln2*li5half-1/
         90*ln2^6+16*li6half+4*s6;
Fill Stab6(-1,0,1,0,-1,1) =13/16*z2*z3*ln2-1/6*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-153/280*z2^3+7/12*z3*ln2^3-303/128*
         z3^2-33/32*z5*ln2+4*ln2*li5half+2*ln2^2*li4half+1/18*ln2^6+
         4*li6half+s6;
Fill Stab6(-1,0,1,0,0,-1) =7/8*z2*z3*ln2+1/6*z2*ln2^4+4*z2*
         li4half-z2^2*ln2^2-337/420*z2^3-69/64*z3^2+41/32*z5*ln2+3/2
         *s6;
Fill Stab6(-1,0,1,0,0,1) =-z2*z3*ln2-1/12*z2*ln2^4-2*z2*
         li4half+1/2*z2^2*ln2^2+17/1680*z2^3+41/32*z3^2+41/32*z5*ln2
         -s6;
Fill Stab6(-1,0,1,0,1,-1) =3/4*z2*z3*ln2-1/6*z2*ln2^4+4*z2*
         li4half-1/20*z2^2*ln2^2-97/140*z2^3-61/32*z3^2-125/16*z5*ln2
         +8*ln2*li5half+4*ln2^2*li4half+1/10*ln2^6+4*s6;
Fill Stab6(-1,0,1,0,1,1) =-1/6*z2*ln2^4-2*z2*li4half+1/2*z2^2*
         ln2^2-661/560*z2^3-119/64*z3^2-125/16*z5*ln2+8*ln2*li5half+
         2*ln2^2*li4half+1/30*ln2^6+12*li6half+19/4*s6;
Fill Stab6(-1,0,1,1,-1,-1) =21/16*z2*z3*ln2+25/48*z2*ln2^4-263/
         80*z2^2*ln2^2-1133/280*z2^3+7/16*z3*ln2^3-237/64*z3^2-35/32*
         z5*ln2+4*ln2*li5half+1/240*ln2^6+27*li6half+43/4*s6;
Fill Stab6(-1,0,1,1,-1,1) =3/2*z2*z3*ln2+1/12*z2*ln2^4+3/2*z2*
         li4half-53/20*z2^2*ln2^2-71/28*z2^3+7/16*z3*ln2^3-723/128*
         z3^2-35/32*z5*ln2+4*ln2*li5half+3/2*ln2^2*li4half+7/120*ln2^6
         +21*li6half+17/2*s6;
Fill Stab6(-1,0,1,1,0,-1) =41/16*z2*z3*ln2+1/8*z2*ln2^4+3*z2*
         li4half-3/4*z2^2*ln2^2-69/112*z2^3-181/128*z3^2+177/64*z5*ln2
         -7/4*s6;
Fill Stab6(-1,0,1,1,0,1) =-11/8*z2*z3*ln2-1/16*z2*ln2^4-3/2*z2
         *li4half+3/8*z2^2*ln2^2-9/28*z2^3+7/4*z3^2+177/64*z5*ln2-s6;
Fill Stab6(-1,0,1,1,1,-1) =-7/8*z2*z3*ln2-5/16*z2*ln2^4+2*z2*
         li4half+3/16*z2^2*ln2^2+2/35*z2^3+7/24*z3*ln2^3-73/64*z3^2-
         4*z5*ln2+4*ln2*li5half+2*ln2^2*li4half+7/144*ln2^6-li6half+
         11/4*s6;
Fill Stab6(-1,0,1,1,1,1) =-7/8*z2*z3*ln2-5/24*z2*ln2^4-3/2*z2*
         li4half+3/8*z2^2*ln2^2-18/35*z2^3+7/24*z3*ln2^3-11/64*z3^2-
         4*z5*ln2+4*ln2*li5half+3/2*ln2^2*li4half+13/360*ln2^6+5*
         li6half+5/2*s6;
Fill Stab6(-1,1,-1,-1,-1,-1) =-13/8*z2*z3*ln2+5/48*z2*ln2^4-1/
         16*z2^2*ln2^2-3/80*z2^3-11/24*z3*ln2^3-169/64*z3^2-375/64*z5*
         ln2+3*ln2*li5half-11/720*ln2^6+6*li6half+6*s6;
Fill Stab6(-1,1,-1,-1,-1,1) =-13/8*z2*z3*ln2+5/48*z2*ln2^4-1/
         16*z2^2*ln2^2-1207/1680*z2^3-11/24*z3*ln2^3+23/64*z3^2-375/64
         *z5*ln2+3*ln2*li5half-11/720*ln2^6+6*li6half+6*s6;
Fill Stab6(-1,1,-1,-1,0,-1) =-13/4*z2*z3*ln2-1/6*z2*ln2^4-3/2*
         z2*li4half+11/40*z2^2*ln2^2-187/560*z2^3+1/6*z3*ln2^3-35/64*
         z3^2-247/32*z5*ln2+5*ln2*li5half+3/2*ln2^2*li4half+1/30*ln2^6
         +9*li6half+29/4*s6;
Fill Stab6(-1,1,-1,-1,0,1) =7/8*z2*z3*ln2-5/48*z2*ln2^4-1/40*
         z2^2*ln2^2-157/560*z2^3+1/6*z3*ln2^3-97/32*z3^2-247/32*z5*ln2
         +5*ln2*li5half+3/2*ln2^2*li4half+7/240*ln2^6+6*li6half+17/4
         *s6;
Fill Stab6(-1,1,-1,-1,1,-1) =1/16*z2*z3*ln2-7/48*z2*ln2^4-3/2*z2
         *li4half+5/16*z2^2*ln2^2-23/35*z2^3-1/48*z3*ln2^3-179/128*
         z3^2-6*z5*ln2+6*ln2*li5half+3/2*ln2^2*li4half+19/720*ln2^6+
         9*li6half+15/4*s6;
Fill Stab6(-1,1,-1,-1,1,1) =1/16*z2*z3*ln2-7/48*z2*ln2^4-3/2*z2*
         li4half+5/16*z2^2*ln2^2-27/35*z2^3-1/48*z3*ln2^3-243/128*z3^2
         -6*z5*ln2+6*ln2*li5half+3/2*ln2^2*li4half+19/720*ln2^6+9*
         li6half+15/4*s6;
Fill Stab6(-1,1,-1,0,-1,-1) =-1/8*z2*z3*ln2-1/4*z2*ln2^4-2*z2*
         li4half+51/40*z2^2*ln2^2+191/280*z2^3+5/48*z3*ln2^3-5/64*z3^2
         -221/32*z5*ln2+7*ln2*li5half+2*ln2^2*li4half+1/40*ln2^6;
Fill Stab6(-1,1,-1,0,-1,1) =-5/16*z2*z3*ln2-3/16*z2*ln2^4-2*z2
         *li4half+39/80*z2^2*ln2^2-101/140*z2^3+5/48*z3*ln2^3-95/64*
         z3^2-221/32*z5*ln2+7*ln2*li5half+2*ln2^2*li4half+3/80*ln2^6
         +9*li6half+15/4*s6;
Fill Stab6(-1,1,-1,0,0,-1) =7/16*z2*z3*ln2-1/24*z2*ln2^4-19/80*
         z2^2*ln2^2-51/112*z2^3+1/8*z3*ln2^3-5/2*z3^2-47/8*z5*ln2+4*
         ln2*li5half+ln2^2*li4half+1/60*ln2^6+6*li6half+17/4*s6;
Fill Stab6(-1,1,-1,0,0,1) =-2*z2*z3*ln2-1/8*z2*ln2^4-z2*
         li4half+3/20*z2^2*ln2^2-2/5*z2^3+1/8*z3*ln2^3-93/128*z3^2-
         47/8*z5*ln2+4*ln2*li5half+ln2^2*li4half+7/360*ln2^6+8*li6half
         +11/2*s6;
Fill Stab6(-1,1,-1,0,1,-1) =-11/8*z2*z3*ln2+3/8*z2*ln2^4+2*z2*
         li4half-27/20*z2^2*ln2^2-27/40*z2^3-23/48*z3*ln2^3-163/64*
         z3^2+85/64*z5*ln2-4*ln2*li5half-2*ln2^2*li4half-1/24*ln2^6+
         6*li6half+6*s6;
Fill Stab6(-1,1,-1,0,1,1) =-19/16*z2*z3*ln2+7/48*z2*ln2^4-z2*
         li4half+11/80*z2^2*ln2^2+61/280*z2^3-23/48*z3*ln2^3+75/32*
         z3^2+85/64*z5*ln2-4*ln2*li5half-2*ln2^2*li4half-37/720*ln2^6
         -li6half+1/4*s6;
Fill Stab6(-1,1,-1,1,-1,-1) =1/16*z2*z3*ln2-1/48*z2*ln2^4+3/16*
         z2^2*ln2^2+53/560*z2^3-1/48*z3*ln2^3+1/128*z3^2-3/64*z5*ln2
         +1/720*ln2^6;
Fill Stab6(-1,1,-1,1,-1,1) =1/16*z2*z3*ln2-1/48*z2*ln2^4+3/16*
         z2^2*ln2^2-123/560*z2^3-1/48*z3*ln2^3+1/128*z3^2-3/64*z5*ln2
         +1/720*ln2^6;
Fill Stab6(-1,1,-1,1,0,-1) =-1/12*z2*ln2^4-z2*li4half+9/40*
         z2^2*ln2^2-139/280*z2^3+1/48*z3*ln2^3-129/128*z3^2-277/64*z5*
         ln2+4*ln2*li5half+ln2^2*li4half+11/720*ln2^6+5*li6half+5/2*
         s6;
Fill Stab6(-1,1,-1,1,0,1) =-3/16*z2*z3*ln2+1/24*z2*ln2^4+2*z2*
         li4half-3/5*z2^2*ln2^2-23/20*z2^3+1/48*z3*ln2^3-63/32*z3^2-
         277/64*z5*ln2+4*ln2*li5half+ln2^2*li4half+7/360*ln2^6+8*
         li6half+11/2*s6;
Fill Stab6(-1,1,-1,1,1,-1) =-1/2*z2*z3*ln2+1/16*z2*ln2^4+1/2*
         z2*li4half+1/16*z2^2*ln2^2+13/105*z2^3-1/6*z3*ln2^3-7/32*z3^2
         -1/32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-1/80*ln2^6-
         li6half+1/4*s6;
Fill Stab6(-1,1,-1,1,1,1) =-1/2*z2*z3*ln2+1/16*z2*ln2^4+1/2*z2
         *li4half+1/16*z2^2*ln2^2+1/7*z2^3-1/6*z3*ln2^3+25/32*z3^2-1/
         32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-1/80*ln2^6-li6half+
         1/4*s6;
Fill Stab6(-1,1,0,-1,-1,-1) =21/16*z2*z3*ln2+31/48*z2*ln2^4+2*z2
         *li4half-263/80*z2^2*ln2^2-263/80*z2^3-7/16*z3*ln2^3-459/128*
         z3^2+99/32*z5*ln2-3*ln2*li5half-2*ln2^2*li4half-7/240*ln2^6
         +21*li6half+10*s6;
Fill Stab6(-1,1,0,-1,-1,1) =19/48*z2*ln2^4+2*z2*li4half-59/20*
         z2^2*ln2^2-197/80*z2^3-111/32*z3^2+99/32*z5*ln2-3*ln2*li5half
         -2*ln2^2*li4half-3/80*ln2^6+15*li6half+37/4*s6;
Fill Stab6(-1,1,0,-1,0,-1) =-5/16*z2*z3*ln2+1/12*z2*ln2^4-17/
         16*z2^2*ln2^2-178/105*z2^3-37/16*z3^2-103/32*z5*ln2+4*ln2*
         li5half-1/60*ln2^6+12*li6half+7*s6;
Fill Stab6(-1,1,0,-1,0,1) =19/8*z2*z3*ln2+1/3*z2*ln2^4+4*z2*
         li4half-13/20*z2^2*ln2^2-3571/1680*z2^3-7/12*z3*ln2^3-217/128
         *z3^2-103/32*z5*ln2+4*ln2*li5half-1/45*ln2^6+8*li6half+15/4
         *s6;
Fill Stab6(-1,1,0,-1,1,-1) =-7/24*z2*ln2^4+13/20*z2^2*ln2^2-
         103/560*z2^3+9/32*z3^2-25/32*z5*ln2+ln2*li5half-1/120*ln2^6
         -3/4*s6;
Fill Stab6(-1,1,0,-1,1,1) =7/16*z2*z3*ln2+1/12*z2*ln2^4+z2*
         li4half+7/20*z2^2*ln2^2-251/560*z2^3-7/48*z3*ln2^3+19/128*
         z3^2-25/32*z5*ln2+ln2*li5half-1/180*ln2^6+2*li6half-1/4*s6;
Fill Stab6(-1,1,0,0,-1,-1) =-11/16*z2*z3*ln2+z2*li4half+7/80*
         z2^2*ln2^2+41/210*z2^3-7/24*z3*ln2^3-9/64*z3^2+39/16*z5*ln2
         -4*ln2*li5half-ln2^2*li4half-1/90*ln2^6-2*li6half-1/4*s6;
Fill Stab6(-1,1,0,0,-1,1) =-7/4*z2*z3*ln2-1/12*z2*ln2^4-3*z2*
         li4half+z2^2*ln2^2+673/420*z2^3+179/64*z3^2+39/16*z5*ln2-4*
         ln2*li5half-ln2^2*li4half-1/60*ln2^6-6*li6half-4*s6;
Fill Stab6(-1,1,0,0,0,-1) =-z2*z3*ln2-1/12*z2*ln2^4-2*z2*
         li4half+7/10*z2^2*ln2^2+22/35*z2^3+9/8*z3^2-29/32*z5*ln2-s6;
Fill Stab6(-1,1,0,0,0,1) =1/2*z2*z3*ln2+1/24*z2*ln2^4+z2*li4half
         -17/40*z2^2*ln2^2-59/280*z2^3-65/64*z3^2-29/32*z5*ln2+3/2*
         s6;
Fill Stab6(-1,1,0,0,1,-1) =11/16*z2*z3*ln2+5/24*z2*ln2^4-z2*
         li4half+11/40*z2^2*ln2^2+251/210*z2^3-7/24*z3*ln2^3+211/128*
         z3^2+125/64*z5*ln2-2*ln2*li5half-ln2^2*li4half-13/360*ln2^6
         -8*li6half-4*s6;
Fill Stab6(-1,1,0,0,1,1) =1/8*z2*ln2^4+z2*li4half-4/5*z2^2*ln2^2
         -43/120*z2^3-67/128*z3^2+125/64*z5*ln2-2*ln2*li5half-ln2^2*
         li4half-1/40*ln2^6+3/2*s6;
Fill Stab6(-1,1,0,1,-1,-1) =-21/16*z2*z3*ln2-1/3*z2*ln2^4-1/2*
         z2*li4half+29/8*z2^2*ln2^2+2259/560*z2^3-7/16*z3*ln2^3+237/64
         *z3^2-87/32*z5*ln2+1/2*ln2^2*li4half-1/60*ln2^6-27*li6half-
         43/4*s6;
Fill Stab6(-1,1,0,1,-1,1) =-21/8*z2*z3*ln2-5/24*z2*ln2^4-7/2*
         z2*li4half+233/80*z2^2*ln2^2+417/112*z2^3+681/128*z3^2-87/32*
         z5*ln2+1/2*ln2^2*li4half-1/120*ln2^6-21*li6half-17/2*s6;
Fill Stab6(-1,1,0,1,0,-1) =-37/8*z2*z3*ln2-11/24*z2*ln2^4-7*z2
         *li4half+153/80*z2^2*ln2^2+2641/840*z2^3+7/12*z3*ln2^3+499/
         128*z3^2+73/64*z5*ln2-4*ln2*li5half+1/45*ln2^6-8*li6half-19/
         4*s6;
Fill Stab6(-1,1,0,1,0,1) =23/16*z2*z3*ln2-1/48*z2*ln2^4+3/2*z2*
         li4half+21/80*z2^2*ln2^2+611/420*z2^3+5/32*z3^2+73/64*z5*ln2
         -4*ln2*li5half+1/60*ln2^6-12*li6half-17/4*s6;
Fill Stab6(-1,1,0,1,1,-1) =1/16*z2*ln2^4-9/2*z2*li4half-3/16*
         z2^2*ln2^2+z2^3+45/32*z3^2+6*z5*ln2-6*ln2*li5half-3/2*ln2^2
         *li4half-1/80*ln2^6-15/4*s6;
Fill Stab6(-1,1,0,1,1,1) =7/16*z2*z3*ln2+7/48*z2*ln2^4+3/2*z2*
         li4half-5/16*z2^2*ln2^2+27/35*z2^3-7/48*z3*ln2^3+131/128*z3^2
         +6*z5*ln2-6*ln2*li5half-3/2*ln2^2*li4half-19/720*ln2^6-10*
         li6half-15/4*s6;
Fill Stab6(-1,1,1,-1,-1,-1) =7/8*z2*z3*ln2+5/24*z2*ln2^4+3/2*z2*
         li4half-7/40*z2^2*ln2^2+5/21*z2^3-7/24*z3*ln2^3+75/64*z3^2+
         4*z5*ln2-4*ln2*li5half-3/2*ln2^2*li4half-13/360*ln2^6-6*
         li6half-5/2*s6;
Fill Stab6(-1,1,1,-1,-1,1) =7/8*z2*z3*ln2+5/24*z2*ln2^4+3/2*z2*
         li4half-7/40*z2^2*ln2^2+11/35*z2^3-7/24*z3*ln2^3+11/64*z3^2
         +4*z5*ln2-4*ln2*li5half-3/2*ln2^2*li4half-13/360*ln2^6-6*
         li6half-5/2*s6;
Fill Stab6(-1,1,1,-1,0,-1) =3/8*z2*z3*ln2+3/16*z2*ln2^4+z2*
         li4half-11/40*z2^2*ln2^2+81/280*z2^3-13/48*z3*ln2^3+85/128*
         z3^2+39/8*z5*ln2-4*ln2*li5half-3/2*ln2^2*li4half-3/80*ln2^6
         -6*li6half-5/2*s6;
Fill Stab6(-1,1,1,-1,0,1) =27/16*z2*z3*ln2+5/24*z2*ln2^4+3/2*z2*
         li4half-19/40*z2^2*ln2^2-17/70*z2^3-13/48*z3*ln2^3+65/64*z3^2
         +39/8*z5*ln2-4*ln2*li5half-3/2*ln2^2*li4half-1/30*ln2^6-3*
         li6half-3*s6;
Fill Stab6(-1,1,1,-1,1,-1) =9/16*z2*z3*ln2-1/24*z2*ln2^4+1/5*
         z2^2*ln2^2+1/120*z2^3+7/48*z3*ln2^3+153/128*z3^2+63/32*z5*ln2
         -ln2*li5half+1/180*ln2^6-3*li6half-3*s6;
Fill Stab6(-1,1,1,-1,1,1) =9/16*z2*z3*ln2-1/24*z2*ln2^4+1/5*z2^2
         *ln2^2+121/280*z2^3+7/48*z3*ln2^3+89/128*z3^2+63/32*z5*ln2-
         ln2*li5half+1/180*ln2^6-3*li6half-3*s6;
Fill Stab6(-1,1,1,0,-1,-1) =1/8*z2*z3*ln2-1/24*z2*ln2^4-1/2*z2*
         li4half-29/40*z2^2*ln2^2-927/560*z2^3+1/4*z3*ln2^3-107/128*
         z3^2-1/8*z5*ln2+ln2*li5half+1/2*ln2^2*li4half+1/36*ln2^6+11
         *li6half+13/4*s6;
Fill Stab6(-1,1,1,0,-1,1) =1/8*z2*z3*ln2-5/48*z2*ln2^4+1/2*z2*
         li4half-19/80*z2^2*ln2^2-243/560*z2^3+1/4*z3*ln2^3-111/128*
         z3^2-1/8*z5*ln2+ln2*li5half+1/2*ln2^2*li4half+13/720*ln2^6+
         4*li6half+s6;
Fill Stab6(-1,1,1,0,0,-1) =3/2*z2*z3*ln2+1/6*z2*ln2^4+3*z2*
         li4half-17/20*z2^2*ln2^2-53/35*z2^3-1/6*z3*ln2^3-3/2*z3^2-
         33/32*z5*ln2+2*ln2*li5half-1/120*ln2^6+6*li6half+3*s6;
Fill Stab6(-1,1,1,0,0,1) =1/16*z2*ln2^4-1/2*z2*li4half-9/80*z2^2
         *ln2^2-87/140*z2^3-1/6*z3*ln2^3-19/32*z3^2-33/32*z5*ln2+2*
         ln2*li5half-1/90*ln2^6+4*li6half+7/4*s6;
Fill Stab6(-1,1,1,0,1,-1) =z2*z3*ln2+1/6*z2*ln2^4+7/2*z2*li4half
         -1/10*z2^2*ln2^2-13/35*z2^3-1/3*z3*ln2^3-3/4*z3^2-4*z5*ln2
         +4*ln2*li5half+1/2*ln2^2*li4half-1/60*ln2^6-3*li6half+2*s6;
Fill Stab6(-1,1,1,0,1,1) =z2*z3*ln2+1/16*z2*ln2^4-1/2*z2*li4half
         +9/80*z2^2*ln2^2-23/35*z2^3-1/3*z3*ln2^3-55/32*z3^2-4*z5*
         ln2+4*ln2*li5half+1/2*ln2^2*li4half-1/240*ln2^6+6*li6half+9/
         4*s6;
Fill Stab6(-1,1,1,1,-1,-1) =-7/16*z2*z3*ln2-1/12*z2*ln2^4-1/2*
         z2*li4half+1/8*z2^2*ln2^2+7/48*z3*ln2^3+49/128*z3^2-z5*ln2+
         ln2*li5half+1/2*ln2^2*li4half+1/72*ln2^6;
Fill Stab6(-1,1,1,1,-1,1) =-7/16*z2*z3*ln2-1/12*z2*ln2^4-1/2*
         z2*li4half+1/8*z2^2*ln2^2+2/5*z2^3+7/48*z3*ln2^3-15/128*z3^2
         -z5*ln2+ln2*li5half+1/2*ln2^2*li4half+1/72*ln2^6;
Fill Stab6(-1,1,1,1,0,-1) =-1/2*z2*z3*ln2-1/12*z2*ln2^4-z2*
         li4half+3/20*z2^2*ln2^2+3/7*z2^3+1/6*z3*ln2^3+3/8*z3^2+z5*
         ln2-ln2*li5half+1/120*ln2^6-s6;
Fill Stab6(-1,1,1,1,0,1) =-1/2*z2*z3*ln2-1/24*z2*ln2^4-1/40*
         z2^2*ln2^2+1/5*z2^3+1/6*z3*ln2^3+5/8*z3^2+z5*ln2-ln2*
         li5half+1/240*ln2^6-3*li6half-1/2*s6;
Fill Stab6(-1,1,1,1,1,-1) =8/35*z2^3-li6half;
Fill Stab6(-1,1,1,1,1,1) =-li6half;
Fill Stab6(0,-1,-1,-1,-1,-1) =-33/16*z2*z3*ln2-5/12*z2*ln2^4+
         11/8*z2^2*ln2^2+20/7*z2^3-7/16*z3*ln2^3+41/32*z3^2-93/64*z5*
         ln2-3*ln2*li5half+1/360*ln2^6-16*li6half-4*s6;
Fill Stab6(0,-1,-1,-1,-1,1) =-27/16*z2*z3*ln2-1/4*z2*ln2^4+93/
         80*z2^2*ln2^2+447/560*z2^3-7/16*z3*ln2^3+105/32*z3^2-1/80*
         ln2^6-9*li6half-7/4*s6;
Fill Stab6(0,-1,-1,-1,0,-1) =-33/8*z2*z3*ln2-3/8*z2^2*ln2^2+7/
         24*z2^3+73/128*z3^2+5*s6;
Fill Stab6(0,-1,-1,-1,0,1) =-3/16*z2*z3*ln2-1/3*z2*ln2^4+17/5*
         z2^2*ln2^2+5687/840*z2^3+55/8*z3^2+31/4*z5*ln2-16*ln2*li5half
         +1/15*ln2^6-48*li6half-21*s6;
Fill Stab6(0,-1,-1,-1,1,-1) =-21/8*z2*z3*ln2-3/8*z2*ln2^4-3*z2
         *li4half+279/80*z2^2*ln2^2+1501/560*z2^3-7/16*z3*ln2^3+243/64
         *z3^2+3/2*ln2^2*li4half+1/24*ln2^6-15*li6half-15/2*s6;
Fill Stab6(0,-1,-1,-1,1,1) =-19/48*z2*ln2^4-3/2*z2*li4half+251/
         80*z2^2*ln2^2+261/80*z2^3-7/16*z3*ln2^3+147/64*z3^2-465/64*z5
         *ln2-ln2*li5half+3/2*ln2^2*li4half+11/240*ln2^6-18*li6half-
         7*s6;
Fill Stab6(0,-1,-1,0,-1,-1) =-15/16*z2*z3*ln2-7/12*z2*ln2^4-2*
         z2*li4half+171/40*z2^2*ln2^2+239/70*z2^3+649/128*z3^2+4*ln2^2
         *li4half+2/15*ln2^6-24*li6half-13*s6;
Fill Stab6(0,-1,-1,0,-1,1) =-15/16*z2*z3*ln2-1/3*z2*ln2^4-4*z2
         *li4half+z2^2*ln2^2-46/35*z2^3-599/128*z3^2-1457/64*z5*ln2+
         16*ln2*li5half+4*ln2^2*li4half+1/15*ln2^6+24*li6half+13*s6;
Fill Stab6(0,-1,-1,0,0,-1) =-9/8*z2*z3*ln2-1/12*z2*ln2^4-2*z2*
         li4half+1/2*z2^2*ln2^2+559/336*z2^3-15/8*z3^2-155/16*z5*ln2
         +4*s6;
Fill Stab6(0,-1,-1,0,0,1) =-9/8*z2*z3*ln2+1/6*z2*ln2^4+4*z2*
         li4half-z2^2*ln2^2-1279/1680*z2^3-53/64*z3^2+5*s6;
Fill Stab6(0,-1,-1,0,1,-1) =-57/16*z2*z3*ln2+1/3*z2*ln2^4-151/
         40*z2^2*ln2^2-162/35*z2^3-11*z3^2-1271/64*z5*ln2+16*ln2*
         li5half-1/15*ln2^6+48*li6half+30*s6;
Fill Stab6(0,-1,-1,0,1,1) =3/8*z2*z3*ln2+1/16*z2*ln2^4+3/2*z2*
         li4half-3/8*z2^2*ln2^2-117/112*z2^3+127/64*z3^2+3/2*s6;
Fill Stab6(0,-1,-1,1,-1,-1) =13/48*z2*ln2^4+1/2*z2*li4half+63/40
         *z2^2*ln2^2+143/140*z2^3+45/32*z3^2+1/2*ln2^2*li4half+1/120*
         ln2^6-9*li6half-15/4*s6;
Fill Stab6(0,-1,-1,1,-1,1) =3/16*z2*z3*ln2+11/48*z2*ln2^4-1/2*z2
         *li4half+13/16*z2^2*ln2^2+129/560*z2^3-93/16*z5*ln2+3*ln2*
         li5half+1/2*ln2^2*li4half-1/240*ln2^6;
Fill Stab6(0,-1,-1,1,0,-1) =-3/16*z2*z3*ln2-11/48*z2*ln2^4-3/2
         *z2*li4half+83/40*z2^2*ln2^2+761/210*z2^3+557/128*z3^2+155/64
         *z5*ln2-8*ln2*li5half+1/30*ln2^6-24*li6half-23/2*s6;
Fill Stab6(0,-1,-1,1,0,1) =-3/16*z2*z3*ln2+3/16*z2*ln2^4+9/2*
         z2*li4half-21/16*z2^2*ln2^2-613/840*z2^3-247/128*z3^2+21/4*s6;
Fill Stab6(0,-1,-1,1,1,-1) =-21/16*z2*z3*ln2-1/12*z2*ln2^4-21/
         16*z2^2*ln2^2+18/35*z2^3-107/64*z3^2-155/32*z5*ln2+ln2*
         li5half-1/180*ln2^6+2*li6half+19/4*s6;
Fill Stab6(0,-1,-1,1,1,1) =1/16*z2*ln2^4+3/2*z2*li4half-39/80*
         z2^2*ln2^2-2/35*z2^3+1/32*z3^2-1/240*ln2^6-3*li6half+9/4*s6;
Fill Stab6(0,-1,0,-1,-1,-1) =39/8*z2*z3*ln2+5/12*z2*ln2^4+4*z2*
         li4half-39/20*z2^2*ln2^2-813/280*z2^3-173/64*z3^2-2*ln2^2*
         li4half-1/15*ln2^6+12*li6half+9/2*s6;
Fill Stab6(0,-1,0,-1,-1,1) =1/4*z2*ln2^4+2*z2*li4half-39/40*z2^2
         *ln2^2-233/280*z2^3-25/128*z3^2+403/64*z5*ln2-4*ln2*li5half
         -2*ln2^2*li4half-1/20*ln2^6;
Fill Stab6(0,-1,0,-1,0,-1) =-109/560*z2^3;
Fill Stab6(0,-1,0,-1,0,1) =21/4*z2*z3*ln2+1/4*z2*ln2^4+6*z2*
         li4half-3/2*z2^2*ln2^2-1003/560*z2^3-35/32*z3^2;
Fill Stab6(0,-1,0,-1,1,-1) =-15/16*z2*z3*ln2-1/12*z2*ln2^4+19/
         40*z2^2*ln2^2+61/35*z2^3+113/64*z3^2+31/16*z5*ln2-4*ln2*
         li5half+1/60*ln2^6-12*li6half-9/2*s6;
Fill Stab6(0,-1,0,-1,1,1) =21/16*z2*z3*ln2+1/16*z2*ln2^4+3/2*z2*
         li4half-3/8*z2^2*ln2^2-55/112*z2^3+45/128*z3^2;
Fill Stab6(0,-1,0,0,-1,-1) =-27/8*z2*z3*ln2+25/24*z2^3-51/32*
         z3^2-155/32*z5*ln2+5*s6;
Fill Stab6(0,-1,0,0,-1,1) =-21/8*z2*z3*ln2-1/8*z2*ln2^4-3*z2*
         li4half+3/4*z2^2*ln2^2+193/420*z2^3+179/64*z3^2;
Fill Stab6(0,-1,0,0,0,-1) =-47/840*z2^3+3/4*z3^2;
Fill Stab6(0,-1,0,0,0,1) =143/168*z2^3-33/16*z3^2-31/4*z5*ln2+
         4*s6;
Fill Stab6(0,-1,0,0,1,-1) =27/8*z2*z3*ln2-127/336*z2^3+15/64*
         z3^2-5/2*s6;
Fill Stab6(0,-1,0,0,1,1) =23/120*z2^3-23/32*z3^2-93/32*z5*ln2+
         3/2*s6;
Fill Stab6(0,-1,0,1,-1,-1) =-11/8*z2*z3*ln2+19/20*z2^2*ln2^2+
         20/7*z2^3-7/12*z3*ln2^3+33/32*z3^2-31/32*z5*ln2-4*ln2*li5half
         +1/90*ln2^6-16*li6half-4*s6;
Fill Stab6(0,-1,0,1,-1,1) =-91/16*z2*z3*ln2-1/6*z2*ln2^4-6*z2*
         li4half+79/40*z2^2*ln2^2+109/56*z2^3-7/12*z3*ln2^3+513/128*
         z3^2-1/180*ln2^6-4*li6half-s6;
Fill Stab6(0,-1,0,1,0,-1) =-35/4*z2*z3*ln2-5/12*z2*ln2^4-10*z2
         *li4half+5/2*z2^2*ln2^2+45/16*z2^3+63/16*z3^2;
Fill Stab6(0,-1,0,1,0,1) =7/4*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2+37/80*z2^3-13/4*z3^2-31/4*z5*ln2+4*
         s6;
Fill Stab6(0,-1,0,1,1,-1) =-41/16*z2*z3*ln2+1/16*z2*ln2^4-13/2
         *z2*li4half+23/20*z2^2*ln2^2+51/80*z2^3-7/12*z3*ln2^3+83/128*
         z3^2-2*ln2^2*li4half-13/180*ln2^6+8*li6half+5/4*s6;
Fill Stab6(0,-1,0,1,1,1) =7/4*z2*z3*ln2+1/3*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2+411/560*z2^3-7/12*z3*ln2^3-7/4*z3^2-
         279/64*z5*ln2-4*ln2*li5half-2*ln2^2*li4half-1/18*ln2^6-4*
         li6half+9/4*s6;
Fill Stab6(0,-1,1,-1,-1,-1) =69/16*z2*z3*ln2+11/16*z2*ln2^4+3*z2
         *li4half-21/10*z2^2*ln2^2-92/35*z2^3-321/128*z3^2-3/2*ln2^2*
         li4half-11/240*ln2^6+12*li6half+9/2*s6;
Fill Stab6(0,-1,1,-1,-1,1) =5/8*z2*ln2^4+3/2*z2*li4half-219/80*
         z2^2*ln2^2-491/140*z2^3-501/128*z3^2+279/64*z5*ln2+3*ln2*
         li5half-3/2*ln2^2*li4half-7/120*ln2^6+21*li6half+33/4*s6;
Fill Stab6(0,-1,1,-1,0,-1) =5/24*z2*ln2^4+z2*li4half-39/20*z2^2*
         ln2^2-769/210*z2^3-569/128*z3^2-155/64*z5*ln2+8*ln2*li5half
         -1/30*ln2^6+24*li6half+21/2*s6;
Fill Stab6(0,-1,1,-1,0,1) =63/16*z2*z3*ln2+1/24*z2*ln2^4+z2*
         li4half-1/16*z2^2*ln2^2-241/336*z2^3+91/128*z3^2-13/4*s6;
Fill Stab6(0,-1,1,-1,1,-1) =3/16*z2*z3*ln2-1/48*z2*ln2^4-123/80*
         z2^2*ln2^2-8/5*z2^3-211/128*z3^2+31/64*z5*ln2+ln2*li5half+1/
         144*ln2^6+11*li6half+17/4*s6;
Fill Stab6(0,-1,1,-1,1,1) =3/2*z2*z3*ln2+1/16*z2*ln2^4-27/80*
         z2^2*ln2^2-247/280*z2^3-57/128*z3^2+1/120*ln2^6+6*li6half+3/
         4*s6;
Fill Stab6(0,-1,1,0,-1,-1) =25/128*z3^2-93/64*z5*ln2;
Fill Stab6(0,-1,1,0,-1,1) =9/80*z2^3+25/128*z3^2;
Fill Stab6(0,-1,1,0,0,-1) =21/8*z2*z3*ln2+1/8*z2*ln2^4+3*z2*
         li4half-3/4*z2^2*ln2^2-37/42*z2^3-3/8*z3^2;
Fill Stab6(0,-1,1,0,0,1) =-493/1680*z2^3+7/64*z3^2+31/16*z5*
         ln2-s6;
Fill Stab6(0,-1,1,0,1,-1) =63/16*z2*z3*ln2+3/16*z2*ln2^4+9/2*z2*
         li4half-9/8*z2^2*ln2^2-771/560*z2^3-151/128*z3^2+3/4*s6;
Fill Stab6(0,-1,1,0,1,1) =-75/112*z2^3+65/128*z3^2+465/64*z5*
         ln2-15/4*s6;
Fill Stab6(0,-1,1,1,-1,-1) =-7/16*z2*z3*ln2-13/48*z2*ln2^4+11/
         16*z2^2*ln2^2+481/280*z2^3-7/48*z3*ln2^3+177/128*z3^2-31/32*
         z5*ln2-3*ln2*li5half+7/720*ln2^6-11*li6half-13/4*s6;
Fill Stab6(0,-1,1,1,-1,1) =-31/16*z2*z3*ln2-1/6*z2*ln2^4-3/2*
         z2*li4half+17/20*z2^2*ln2^2+293/280*z2^3-7/48*z3*ln2^3+181/
         128*z3^2-1/180*ln2^6-4*li6half-s6;
Fill Stab6(0,-1,1,1,0,-1) =-35/16*z2*z3*ln2-5/48*z2*ln2^4-5/2*
         z2*li4half+5/8*z2^2*ln2^2+17/21*z2^3+131/128*z3^2;
Fill Stab6(0,-1,1,1,0,1) =7/16*z2*z3*ln2+1/48*z2*ln2^4+1/2*z2*
         li4half-1/8*z2^2*ln2^2+13/60*z2^3-17/16*z3^2-155/32*z5*ln2+
         5/2*s6;
Fill Stab6(0,-1,1,1,1,-1) =7/16*z2*z3*ln2+1/8*z2*ln2^4-1/2*z2*
         li4half+1/10*z2^2*ln2^2-6/35*z2^3-7/48*z3*ln2^3-17/128*z3^2
         -1/2*ln2^2*li4half-13/720*ln2^6+2*li6half+1/2*s6;
Fill Stab6(0,-1,1,1,1,1) =7/16*z2*z3*ln2+1/12*z2*ln2^4+1/2*z2*
         li4half-1/8*z2^2*ln2^2-7/48*z3*ln2^3-49/128*z3^2-ln2*li5half
         -1/2*ln2^2*li4half-1/72*ln2^6-li6half;
Fill Stab6(0,0,-1,-1,-1,-1) =3/2*z2*z3*ln2+1/4*z2*ln2^4-z2*
         li4half+29/40*z2^2*ln2^2+503/1680*z2^3+15/16*z3^2-ln2^2*
         li4half-2/45*ln2^6-2*li6half-11/4*s6;
Fill Stab6(0,0,-1,-1,-1,1) =13/48*z2*ln2^4-1/2*z2*li4half-1/4*
         z2^2*ln2^2-1151/840*z2^3-1/32*z3^2+279/64*z5*ln2+2*ln2*
         li5half-ln2^2*li4half-1/20*ln2^6+6*li6half-3/4*s6;
Fill Stab6(0,0,-1,-1,0,-1) =-1/24*z2*ln2^4-z2*li4half+1/4*z2^2
         *ln2^2-591/560*z2^3+9/4*z3^2+155/16*z5*ln2-6*s6;
Fill Stab6(0,0,-1,-1,0,1) =-1/4*z2*ln2^4-6*z2*li4half+3/2*z2^2
         *ln2^2+327/280*z2^3+11/4*z3^2-5*s6;
Fill Stab6(0,0,-1,-1,1,-1) =39/16*z2*z3*ln2+z2*li4half-31/80*
         z2^2*ln2^2-209/336*z2^3+173/64*z3^2+31/4*z5*ln2-2*ln2*li5half
         +1/120*ln2^6-6*li6half-31/4*s6;
Fill Stab6(0,0,-1,-1,1,1) =-1/12*z2*ln2^4-3*z2*li4half+4/5*
         z2^2*ln2^2+83/60*z2^3+17/64*z3^2-1/360*ln2^6-2*li6half-3*s6;
Fill Stab6(0,0,-1,0,-1,-1) =27/8*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-403/240*z2^3+51/32*z3^2+155/32*z5*ln2
         -5*s6;
Fill Stab6(0,0,-1,0,-1,1) =643/840*z2^3-109/64*z3^2;
Fill Stab6(0,0,-1,0,0,-1) =4/35*z2^3+9/32*z3^2;
Fill Stab6(0,0,-1,0,0,1) =-439/280*z2^3+81/32*z3^2+93/8*z5*ln2
         -6*s6;
Fill Stab6(0,0,-1,0,1,-1) =15/8*z2*z3*ln2+1/6*z2*ln2^4+4*z2*
         li4half-z2^2*ln2^2-11/12*z2^3-99/64*z3^2+5/2*s6;
Fill Stab6(0,0,-1,0,1,1) =-683/840*z2^3+59/64*z3^2+217/32*z5*
         ln2-7/2*s6;
Fill Stab6(0,0,-1,1,-1,-1) =11/16*z2*z3*ln2-3/16*z2*ln2^4+1/2*z2
         *li4half-97/80*z2^2*ln2^2-121/168*z2^3+7/24*z3*ln2^3+9/64*
         z3^2+155/64*z5*ln2-2*ln2*li5half+7/360*ln2^6+2*li6half+1/4*
         s6;
Fill Stab6(0,0,-1,1,-1,1) =7/8*z2*z3*ln2-1/24*z2*ln2^4+2*z2*
         li4half-7/5*z2^2*ln2^2-137/210*z2^3+7/24*z3*ln2^3-193/64*z3^2
         +1/120*ln2^6+6*li6half+4*s6;
Fill Stab6(0,0,-1,1,0,-1) =7/4*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-9/56*z2^3-21/16*z3^2;
Fill Stab6(0,0,-1,1,0,1) =-7/8*z2*z3*ln2-1/24*z2*ln2^4-z2*
         li4half+1/4*z2^2*ln2^2-83/280*z2^3+5/4*z3^2+31/16*z5*ln2-s6;
Fill Stab6(0,0,-1,1,1,-1) =5/8*z2*z3*ln2-1/24*z2*ln2^4+2*z2*
         li4half+7/20*z2^2*ln2^2+337/840*z2^3+7/24*z3*ln2^3+9/64*z3^2
         +ln2^2*li4half+1/30*ln2^6-6*li6half-3/2*s6;
Fill Stab6(0,0,-1,1,1,1) =-7/8*z2*z3*ln2-1/6*z2*ln2^4-z2*
         li4half+1/4*z2^2*ln2^2-85/168*z2^3+7/24*z3*ln2^3+41/64*z3^2
         +31/32*z5*ln2+2*ln2*li5half+ln2^2*li4half+1/36*ln2^6+2*
         li6half-1/2*s6;
Fill Stab6(0,0,0,-1,-1,-1) =-9/8*z2*z3*ln2-3/4*z2^2*ln2^2+1381/
         1680*z2^3-57/32*z3^2-155/32*z5*ln2+4*s6;
Fill Stab6(0,0,0,-1,-1,1) =1/12*z2*ln2^4+2*z2*li4half-7/8*z2^2*
         ln2^2-59/420*z2^3-z3^2+5/2*s6;
Fill Stab6(0,0,0,-1,0,-1) =193/420*z2^3-3/4*z3^2;
Fill Stab6(0,0,0,-1,0,1) =743/840*z2^3-9/4*z3^2-31/4*z5*ln2+4*
         s6;
Fill Stab6(0,0,0,-1,1,-1) =-3/2*z2*z3*ln2-1/12*z2*ln2^4-2*z2*
         li4half+7/8*z2^2*ln2^2+115/168*z2^3+3/8*z3^2;
Fill Stab6(0,0,0,-1,1,1) =113/840*z2^3-5/8*z3^2-93/32*z5*ln2+3/
         2*s6;
Fill Stab6(0,0,0,0,-1,-1) =s6;
Fill Stab6(0,0,0,0,-1,1) =-11/20*z2^3+3/4*z3^2+31/16*z5*ln2-
         s6;
Fill Stab6(0,0,0,0,0,-1) =-31/140*z2^3;
Fill Stab6(0,0,0,0,0,1) =8/35*z2^3;
Fill Stab6(0,0,0,0,1,-1) =7/40*z2^3-9/32*z3^2-31/16*z5*ln2;
Fill Stab6(0,0,0,0,1,1) =2/5*z2^3-1/2*z3^2;
Fill Stab6(0,0,0,1,-1,-1) =9/8*z2*z3*ln2+3/4*z2^2*ln2^2-11/42*
         z2^3+53/64*z3^2-3/2*s6;
Fill Stab6(0,0,0,1,-1,1) =-1/24*z2*ln2^4-z2*li4half+5/8*z2^2*
         ln2^2-607/840*z2^3+15/8*z3^2+155/32*z5*ln2-4*s6;
Fill Stab6(0,0,0,1,0,-1) =-1069/840*z2^3+33/16*z3^2+31/4*z5*
         ln2-4*s6;
Fill Stab6(0,0,0,1,0,1) =-8/105*z2^3+z3^2;
Fill Stab6(0,0,0,1,1,-1) =3/2*z2*z3*ln2+1/24*z2*ln2^4+z2*li4half
         -5/8*z2^2*ln2^2-149/168*z2^3+49/64*z3^2+93/32*z5*ln2-5/2*s6;
Fill Stab6(0,0,0,1,1,1) =89/210*z2^3-1/2*z3^2;
Fill Stab6(0,0,1,-1,-1,-1) =-19/8*z2*z3*ln2-1/6*z2*ln2^4-19/40
         *z2^2*ln2^2+937/840*z2^3-7/24*z3*ln2^3-35/16*z3^2-279/64*z5*
         ln2-2*ln2*li5half+1/60*ln2^6+5*s6;
Fill Stab6(0,0,1,-1,-1,1) =-7/8*z2*z3*ln2+1/24*z2*ln2^4+3*z2*
         li4half-83/80*z2^2*ln2^2-317/210*z2^3-7/24*z3*ln2^3+9/16*z3^2
         +1/180*ln2^6+4*li6half+21/4*s6;
Fill Stab6(0,0,1,-1,0,-1) =-7/4*z2*z3*ln2+1/6*z2*ln2^4+4*z2*
         li4half-z2^2*ln2^2-183/280*z2^3-29/64*z3^2+5*s6;
Fill Stab6(0,0,1,-1,0,1) =7/8*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2+27/35*z2^3-4*z3^2-155/16*z5*ln2+6*s6;
Fill Stab6(0,0,1,-1,1,-1) =-25/16*z2*z3*ln2-1/8*z2*ln2^4-z2*
         li4half+137/80*z2^2*ln2^2+2363/1680*z2^3-7/24*z3*ln2^3+223/
         128*z3^2+ln2^2*li4half+11/360*ln2^6-8*li6half-3*s6;
Fill Stab6(0,0,1,-1,1,1) =7/8*z2*z3*ln2-1/16*z2*ln2^4+1/2*z2*
         li4half+39/80*z2^2*ln2^2+677/1680*z2^3-7/24*z3*ln2^3-251/128*
         z3^2-31/4*z5*ln2+2*ln2*li5half+ln2^2*li4half+1/40*ln2^6+5/2
         *s6;
Fill Stab6(0,0,1,0,-1,-1) =-3/4*z2*z3*ln2-1/6*z2*ln2^4-4*z2*
         li4half+z2^2*ln2^2+13/12*z2^3+23/32*z3^2-3/2*s6;
Fill Stab6(0,0,1,0,-1,1) =677/1680*z2^3-85/64*z3^2-155/32*z5*ln2
         +5/2*s6;
Fill Stab6(0,0,1,0,0,-1) =377/280*z2^3-105/32*z3^2-93/8*z5*ln2
         +6*s6;
Fill Stab6(0,0,1,0,0,1) =4/35*z2^3+1/2*z3^2;
Fill Stab6(0,0,1,0,1,-1) =-9/2*z2*z3*ln2-1/12*z2*ln2^4-2*z2*
         li4half+1/2*z2^2*ln2^2+589/336*z2^3-41/32*z3^2-217/32*z5*ln2
         +5*s6;
Fill Stab6(0,0,1,0,1,1) =-143/210*z2^3+3*z3^2;
Fill Stab6(0,0,1,1,-1,-1) =3/16*z2*z3*ln2+1/6*z2*ln2^4-2*z2*
         li4half+37/40*z2^2*ln2^2+67/120*z2^3+67/128*z3^2-ln2^2*
         li4half-1/24*ln2^6-3/2*s6;
Fill Stab6(0,0,1,1,-1,1) =1/4*z2*ln2^4-17/40*z2^2*ln2^2-205/168*
         z2^3-183/128*z3^2-155/64*z5*ln2+2*ln2*li5half-ln2^2*li4half
         -17/360*ln2^6+8*li6half+4*s6;
Fill Stab6(0,0,1,1,0,-1) =-27/560*z2^3-31/64*z3^2-31/16*z5*ln2
         +s6;
Fill Stab6(0,0,1,1,0,1) =11/35*z2^3;
Fill Stab6(0,0,1,1,1,-1) =-3/2*z2*z3*ln2-5/48*z2*ln2^4-1/2*z2*
         li4half-1/16*z2^2*ln2^2+107/105*z2^3+7/32*z3^2-31/32*z5*ln2
         -2*ln2*li5half+1/90*ln2^6-4*li6half-1/4*s6;
Fill Stab6(0,0,1,1,1,1) =2/105*z2^3+z3^2;
Fill Stab6(0,1,-1,-1,-1,-1) =3/4*z2*z3*ln2+13/24*z2*ln2^4-3/2*z2
         *li4half-z2^2*ln2^2-659/560*z2^3-121/64*z3^2-3/2*ln2^2*
         li4half-2/45*ln2^6+13*li6half+19/4*s6;
Fill Stab6(0,1,-1,-1,-1,1) =3/8*z2*z3*ln2+2/3*z2*ln2^4+3/2*z2*
         li4half-221/80*z2^2*ln2^2-134/35*z2^3-247/64*z3^2+93/64*z5*
         ln2+3*ln2*li5half-3/2*ln2^2*li4half-41/720*ln2^6+22*li6half
         +10*s6;
Fill Stab6(0,1,-1,-1,0,-1) =3/2*z2*z3*ln2+19/48*z2*ln2^4+3/2*z2*
         li4half-151/40*z2^2*ln2^2-2533/336*z2^3-8*z3^2-31/4*z5*ln2+
         16*ln2*li5half-1/15*ln2^6+48*li6half+21*s6;
Fill Stab6(0,1,-1,-1,0,1) =3/2*z2*z3*ln2-1/8*z2*ln2^4-3*z2*
         li4half+9/8*z2^2*ln2^2+59/84*z2^3+7/4*z3^2-5*s6;
Fill Stab6(0,1,-1,-1,1,-1) =63/16*z2*z3*ln2+5/24*z2*ln2^4+9/2*z2
         *li4half-43/16*z2^2*ln2^2-149/35*z2^3-39/64*z3^2+465/64*z5*
         ln2+ln2*li5half+1/120*ln2^6+12*li6half+3/4*s6;
Fill Stab6(0,1,-1,-1,1,1) =21/16*z2*z3*ln2+5/48*z2*ln2^4-29/80*
         z2^2*ln2^2-6/35*z2^3-137/64*z3^2+7/720*ln2^6+7*li6half+3/4*
         s6;
Fill Stab6(0,1,-1,0,-1,-1) =39/8*z2*z3*ln2-1/12*z2*ln2^4+6*z2*
         li4half+91/40*z2^2*ln2^2+177/70*z2^3+347/32*z3^2+1457/64*z5*
         ln2-16*ln2*li5half+1/15*ln2^6-48*li6half-30*s6;
Fill Stab6(0,1,-1,0,-1,1) =15/16*z2*z3*ln2+303/280*z2^3-137/64*
         z3^2-3/2*s6;
Fill Stab6(0,1,-1,0,0,-1) =9/8*z2*z3*ln2-1/6*z2*ln2^4-4*z2*
         li4half+z2^2*ln2^2+139/120*z2^3+41/32*z3^2-5*s6;
Fill Stab6(0,1,-1,0,0,1) =9/8*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-1/2*z2^2*ln2^2-1811/840*z2^3+57/32*z3^2+155/16*z5*ln2
         -4*s6;
Fill Stab6(0,1,-1,0,1,-1) =-3/8*z2*z3*ln2+1/3*z2*ln2^4-4*z2*
         li4half-111/40*z2^2*ln2^2-47/28*z2^3-137/32*z3^2-4*ln2^2*
         li4half-2/15*ln2^6+24*li6half+23/2*s6;
Fill Stab6(0,1,-1,0,1,1) =-3/8*z2*z3*ln2+13/48*z2*ln2^4+5/2*z2
         *li4half-5/8*z2^2*ln2^2+919/560*z2^3+139/32*z3^2+1271/64*z5*
         ln2-16*ln2*li5half-4*ln2^2*li4half-1/15*ln2^6-24*li6half-23/
         2*s6;
Fill Stab6(0,1,-1,1,-1,-1) =21/16*z2*z3*ln2-5/16*z2*ln2^4-3/8*
         z2^2*ln2^2-11/80*z2^3+7/16*z3*ln2^3+165/64*z3^2+93/16*z5*ln2
         -3*ln2*li5half+1/60*ln2^6-6*li6half-6*s6;
Fill Stab6(0,1,-1,1,-1,1) =9/8*z2*z3*ln2-7/48*z2*ln2^4-47/80*
         z2^2*ln2^2+113/140*z2^3+7/16*z3*ln2^3-37/16*z3^2+1/720*ln2^6
         +li6half-1/4*s6;
Fill Stab6(0,1,-1,1,0,-1) =45/16*z2*z3*ln2+1/12*z2*ln2^4+2*z2*
         li4half-5/16*z2^2*ln2^2+1/105*z2^3-191/128*z3^2-7/4*s6;
Fill Stab6(0,1,-1,1,0,1) =-9/8*z2*z3*ln2+1/16*z2*ln2^4-5/2*z2*
         li4half-43/40*z2^2*ln2^2-5777/1680*z2^3-133/64*z3^2-155/64*z5
         *ln2+8*ln2*li5half-1/30*ln2^6+24*li6half+9*s6;
Fill Stab6(0,1,-1,1,1,-1) =1/12*z2*ln2^4-1/2*z2*li4half-77/80*
         z2^2*ln2^2-45/112*z2^3+7/16*z3*ln2^3-31/16*z3^2-1/2*ln2^2*
         li4half-1/90*ln2^6+7*li6half+4*s6;
Fill Stab6(0,1,-1,1,1,1) =-21/16*z2*z3*ln2-1/48*z2*ln2^4-z2*
         li4half-13/16*z2^2*ln2^2-559/560*z2^3+7/16*z3*ln2^3+1/2*z3^2
         +155/32*z5*ln2-ln2*li5half-1/2*ln2^2*li4half-1/144*ln2^6+4*
         li6half+s6;
Fill Stab6(0,1,0,-1,-1,-1) =-25/8*z2*z3*ln2-1/4*z2*ln2^4-6*z2*
         li4half-53/40*z2^2*ln2^2-1/14*z2^3+7/12*z3*ln2^3-69/32*z3^2
         -403/64*z5*ln2+4*ln2*li5half-1/90*ln2^6+16*li6half+8*s6;
Fill Stab6(0,1,0,-1,-1,1) =7/4*z2*z3*ln2-1/12*z2*ln2^4-113/80*
         z2^2*ln2^2+101/280*z2^3+7/12*z3*ln2^3-99/32*z3^2+1/180*ln2^6
         +4*li6half+7/4*s6;
Fill Stab6(0,1,0,-1,0,-1) =7/2*z2*z3*ln2+1/6*z2*ln2^4+4*z2*
         li4half-z2^2*ln2^2-41/140*z2^3-91/32*z3^2;
Fill Stab6(0,1,0,-1,0,1) =-7*z2*z3*ln2-1/3*z2*ln2^4-8*z2*
         li4half+2*z2^2*ln2^2+73/35*z2^3+35/16*z3^2;
Fill Stab6(0,1,0,-1,1,-1) =-13/16*z2*z3*ln2-1/4*z2*ln2^4+2*z2*
         li4half+73/80*z2^2*ln2^2+67/70*z2^3+7/12*z3*ln2^3+7/128*z3^2
         +2*ln2^2*li4half+13/180*ln2^6-8*li6half-5/4*s6;
Fill Stab6(0,1,0,-1,1,1) =-49/16*z2*z3*ln2-19/48*z2*ln2^4-7/2*
         z2*li4half+7/8*z2^2*ln2^2-69/560*z2^3+7/12*z3*ln2^3+137/128*
         z3^2-31/16*z5*ln2+4*ln2*li5half+2*ln2^2*li4half+1/18*ln2^6+
         4*li6half+s6;
Fill Stab6(0,1,0,0,-1,-1) =-15/8*z2*z3*ln2+389/840*z2^3-59/64*
         z3^2+7/2*s6;
Fill Stab6(0,1,0,0,-1,1) =21/8*z2*z3*ln2+1/8*z2*ln2^4+3*z2*
         li4half-3/4*z2^2*ln2^2-253/120*z2^3+71/64*z3^2+155/32*z5*ln2
         -5/2*s6;
Fill Stab6(0,1,0,0,0,-1) =-1223/840*z2^3+9/4*z3^2+31/4*z5*ln2
         -4*s6;
Fill Stab6(0,1,0,0,0,1) =74/105*z2^3-z3^2;
Fill Stab6(0,1,0,0,1,-1) =15/8*z2*z3*ln2-295/336*z2^3+55/32*z3^2
         +93/32*z5*ln2-5*s6;
Fill Stab6(0,1,0,0,1,1) =29/21*z2^3-3*z3^2;
Fill Stab6(0,1,0,1,-1,-1) =-3/8*z2*z3*ln2-1/6*z2*ln2^4+2*z2*
         li4half+93/40*z2^2*ln2^2+661/560*z2^3+119/64*z3^2+2*ln2^2*
         li4half+1/15*ln2^6-12*li6half-19/4*s6;
Fill Stab6(0,1,0,1,-1,1) =63/16*z2*z3*ln2+4*z2*li4half+33/80*
         z2^2*ln2^2-1453/560*z2^3+5/4*z3^2+31/32*z5*ln2+4*ln2*li5half
         +2*ln2^2*li4half+1/20*ln2^6-4*s6;
Fill Stab6(0,1,0,1,0,-1) =21/4*z2*z3*ln2+1/4*z2*ln2^4+6*z2*
         li4half-3/2*z2^2*ln2^2-1943/560*z2^3+17/16*z3^2+31/4*z5*ln2
         -4*s6;
Fill Stab6(0,1,0,1,0,1) =31/70*z2^3;
Fill Stab6(0,1,0,1,1,-1) =69/16*z2*z3*ln2+13/48*z2*ln2^4+9/2*z2*
         li4half-203/80*z2^2*ln2^2-149/35*z2^3-41/64*z3^2+279/64*z5*
         ln2+4*ln2*li5half-1/60*ln2^6+12*li6half+3/4*s6;
Fill Stab6(0,1,0,1,1,1) =8/7*z2^3-2*z3^2;
Fill Stab6(0,1,1,-1,-1,-1) =-31/8*z2*z3*ln2-11/16*z2*ln2^4-9/2
         *z2*li4half+6/5*z2^2*ln2^2+23/7*z2^3+7/48*z3*ln2^3+25/32*z3^2
         -279/64*z5*ln2-3*ln2*li5half+1/80*ln2^6-9*li6half-3/2*s6;
Fill Stab6(0,1,1,-1,-1,1) =7/16*z2*z3*ln2-1/3*z2*ln2^4-11/80*
         z2^2*ln2^2+6/35*z2^3+7/48*z3*ln2^3+137/64*z3^2-1/360*ln2^6-
         2*li6half-3/4*s6;
Fill Stab6(0,1,1,-1,0,-1) =7/8*z2*z3*ln2+1/24*z2*ln2^4+z2*
         li4half-7/16*z2^2*ln2^2-47/420*z2^3+129/128*z3^2-1/4*s6;
Fill Stab6(0,1,1,-1,0,1) =-35/8*z2*z3*ln2-5/16*z2*ln2^4-7/2*z2
         *li4half+103/40*z2^2*ln2^2+7837/1680*z2^3+177/64*z3^2+155/64*
         z5*ln2-8*ln2*li5half+1/30*ln2^6-24*li6half-8*s6;
Fill Stab6(0,1,1,-1,1,-1) =-5/8*z2*z3*ln2-13/48*z2*ln2^4+3/2*
         z2*li4half+17/16*z2^2*ln2^2+55/56*z2^3+7/48*z3*ln2^3+37/64*
         z3^2+3/2*ln2^2*li4half+37/720*ln2^6-8*li6half-5/4*s6;
Fill Stab6(0,1,1,-1,1,1) =-31/16*z2*z3*ln2-23/48*z2*ln2^4-3/2*
         z2*li4half+147/80*z2^2*ln2^2+25/14*z2^3+7/48*z3*ln2^3+81/64*
         z3^2-31/64*z5*ln2-ln2*li5half+3/2*ln2^2*li4half+1/18*ln2^6-
         11*li6half-17/4*s6;
Fill Stab6(0,1,1,0,-1,-1) =-21/16*z2*z3*ln2+75/112*z2^3-225/
         128*z3^2+15/4*s6;
Fill Stab6(0,1,1,0,-1,1) =-15/28*z2^3-9/128*z3^2+93/64*z5*ln2
         -3/4*s6;
Fill Stab6(0,1,1,0,0,-1) =-21/8*z2*z3*ln2-1/8*z2*ln2^4-3*z2*
         li4half+3/4*z2^2*ln2^2+769/840*z2^3-17/32*z3^2-31/16*z5*ln2
         +s6;
Fill Stab6(0,1,1,0,0,1) =17/42*z2^3+1/2*z3^2;
Fill Stab6(0,1,1,0,1,-1) =-21/8*z2*z3*ln2-3/16*z2*ln2^4-9/2*z2
         *li4half+9/8*z2^2*ln2^2+9/5*z2^3+15/32*z3^2-465/64*z5*ln2;
Fill Stab6(0,1,1,0,1,1) =2*z3^2;
Fill Stab6(0,1,1,1,-1,-1) =13/48*z2*ln2^4+1/2*z2*li4half+27/16*
         z2^2*ln2^2+44/35*z2^3-1/32*z3^2+1/2*ln2^2*li4half+1/80*ln2^6
         -6*li6half-9/4*s6;
Fill Stab6(0,1,1,1,-1,1) =3/2*z2*z3*ln2+7/24*z2*ln2^4+z2*li4half
         +11/20*z2^2*ln2^2-71/35*z2^3+3/4*z3^2+31/32*z5*ln2+3*ln2*
         li5half+1/2*ln2^2*li4half+3*li6half-2*s6;
Fill Stab6(0,1,1,1,0,-1) =21/16*z2*z3*ln2+1/16*z2*ln2^4+3/2*z2*
         li4half-3/8*z2^2*ln2^2-26/15*z2^3+45/64*z3^2+155/32*z5*ln2-
         5/2*s6;
Fill Stab6(0,1,1,1,0,1) =118/105*z2^3-z3^2;
Fill Stab6(0,1,1,1,1,-1) =-1/12*z2*ln2^4-6/5*z2^2*ln2^2-8/7*
         z2^3+ln2*li5half-1/720*ln2^6+5*li6half;
Fill Stab6(0,1,1,1,1,1) =8/7*z2^3;
Fill Stab6(1,-1,-1,-1,-1,-1) =-9/8*z2*z3*ln2-1/8*z2*z3*Sinf-1/
         12*z2*ln2^3*Sinf-1/48*z2*ln2^4-9/40*z2^2*ln2*Sinf+3/8*z2^2*
         ln2^2+34/35*z2^3-1/8*z3*ln2^2*Sinf-5/12*z3*ln2^3-27/64*z3^2
         -2*z5*ln2-3/16*z5*Sinf-1/120*ln2^5*Sinf-1/90*ln2^6-3*
         li6half+3/4*s6;
Fill Stab6(1,-1,-1,-1,-1,1) =-9/8*z2*z3*ln2-1/8*z2*z3*Sinf-1/
         12*z2*ln2^3*Sinf-1/48*z2*ln2^4-9/40*z2^2*ln2*Sinf+3/8*z2^2*
         ln2^2-6/35*z2^3-1/8*z3*ln2^2*Sinf-5/12*z3*ln2^3+101/64*z3^2
         +29/16*z5*Sinf-1/120*ln2^5*Sinf-1/90*ln2^6-3*li6half+3/4*s6;
Fill Stab6(1,-1,-1,-1,0,-1) =-5/2*z2*z3*ln2-3/4*z2*z3*Sinf+1/
         12*z2*ln2^3*Sinf+1/16*z2*ln2^4+3/8*z2^2*ln2*Sinf+13/20*z2^2*
         ln2^2+241/280*z2^3-1/2*z3*ln2^2*Sinf-1/3*z3*ln2^3+35/16*z3^2
         +29/64*z5*Sinf-1/40*ln2^5*Sinf-1/80*ln2^6+3*Sinf*li5half-9*
         li6half;
Fill Stab6(1,-1,-1,-1,0,1) =1/2*z2*z3*ln2-3/8*z2*z3*Sinf+1/12*z2
         *ln2^3*Sinf-1/48*z2*ln2^4+3/5*z2^2*ln2*Sinf+83/80*z2^2*ln2^2+
         859/560*z2^3-1/2*z3*ln2^2*Sinf-1/3*z3*ln2^3+55/64*z3^2-93/64*
         z5*ln2-z5*Sinf-3*ln2*li5half+1/72*ln2^6-8*li6half-15/4*s6;
Fill Stab6(1,-1,-1,-1,1,-1) =-7/16*z2*z3*ln2-23/16*z2*z3*Sinf+
         5/12*z2*ln2^3*Sinf+7/24*z2*ln2^4+19/40*z2^2*ln2*Sinf+43/40*z2^2
         *ln2^2-29/60*z2^3-23/16*z3*ln2^2*Sinf-31/24*z3*ln2^3+177/128*
         z3^2+375/64*z5*Sinf-3*ln2*Sinf*li4half-3/2*ln2^2*li4half-13/
         120*ln2^5*Sinf-5/72*ln2^6-3*Sinf*li5half;
Fill Stab6(1,-1,-1,-1,1,1) =25/16*z2*z3*ln2+9/16*z2*z3*Sinf+5/12
         *z2*ln2^3*Sinf+7/24*z2*ln2^4+19/40*z2^2*ln2*Sinf+43/40*z2^2*
         ln2^2+29/60*z2^3-23/16*z3*ln2^2*Sinf-31/24*z3*ln2^3-79/128*
         z3^2-11/2*z5*ln2+23/64*z5*Sinf-3*ln2*Sinf*li4half-3/2*ln2^2*
         li4half-13/120*ln2^5*Sinf-5/72*ln2^6-3*Sinf*li5half;
Fill Stab6(1,-1,-1,0,-1,-1) =z2*z3*ln2-13/8*z2*z3*Sinf+5/6*z2*
         ln2^3*Sinf+5/16*z2*ln2^4+3/2*z2*li4half-41/40*z2^2*ln2*Sinf-
         91/80*z2^2*ln2^2-261/80*z2^3-13/8*z3*ln2^2*Sinf-13/12*z3*ln2^3
         -7/4*z3^2+845/64*z5*Sinf-4*ln2*Sinf*li4half-1/2*ln2^2*li4half
         -3/40*ln2^5*Sinf+1/240*ln2^6-11*Sinf*li5half+18*li6half+7*
         s6;
Fill Stab6(1,-1,-1,0,-1,1) =z2*z3*ln2+z2*z3*Sinf+7/12*z2*ln2^3*
         Sinf+1/4*z2*ln2^4-3/2*z2*li4half+1/40*z2^2*ln2*Sinf+29/80*
         z2^2*ln2^2-493/560*z2^3-13/8*z3*ln2^2*Sinf-13/12*z3*ln2^3-13/
         4*z3^2-93/8*z5*ln2+101/64*z5*Sinf-4*ln2*Sinf*li4half+6*ln2*
         li5half-1/2*ln2^2*li4half-1/8*ln2^5*Sinf-1/20*ln2^6-5*Sinf*
         li5half+15*li6half+15/2*s6;
Fill Stab6(1,-1,-1,0,0,-1) =-3/8*z2*z3*ln2+1/8*z2*z3*Sinf-5/48
         *z2*ln2^4-3/2*z2*li4half+19/40*z2^2*ln2*Sinf+49/40*z2^2*ln2^2
         +1091/560*z2^3-3/8*z3*ln2^2*Sinf-1/4*z3*ln2^3+25/64*z3^2-
         279/64*z5*ln2-15/8*z5*Sinf-2*ln2*li5half+1/120*ln2^6-6*
         li6half-7/4*s6;
Fill Stab6(1,-1,-1,0,0,1) =-3/8*z2*z3*ln2-11/8*z2*z3*Sinf+1/6*
         z2*ln2^3*Sinf+5/24*z2*ln2^4+3*z2*li4half+1/5*z2^2*ln2*Sinf-3/
         5*z2^2*ln2^2-199/280*z2^3-3/8*z3*ln2^2*Sinf-1/4*z3*ln2^3+55/
         64*z3^2+159/64*z5*Sinf-1/60*ln2^5*Sinf-1/180*ln2^6+2*Sinf*
         li5half-4*li6half+9/4*s6;
Fill Stab6(1,-1,-1,0,1,-1) =-5/2*z2*z3*ln2+1/8*z2*z3*Sinf-1/3*
         z2*ln2^3*Sinf-1/24*z2*ln2^4+47/40*z2^2*ln2*Sinf+29/20*z2^2*
         ln2^2+86/35*z2^3+1/8*z3*ln2^2*Sinf+1/12*z3*ln2^3+25/64*z3^2
         -93/16*z5*ln2-61/8*z5*Sinf+ln2*Sinf*li4half+4*ln2*li5half+1/
         2*ln2^2*li4half-1/40*ln2^5*Sinf-7/240*ln2^6+8*Sinf*li5half-12
         *li6half-3/4*s6;
Fill Stab6(1,-1,-1,0,1,1) =1/8*z2*z3*ln2+1/8*z2*z3*Sinf+1/12*z2*
         ln2^3*Sinf+1/48*z2*ln2^4+9/40*z2^2*ln2*Sinf-3/8*z2^2*ln2^2+6/
         35*z2^3+1/8*z3*ln2^2*Sinf+1/12*z3*ln2^3+123/64*z3^2-29/16*z5*
         Sinf+ln2*Sinf*li4half+1/2*ln2^2*li4half+1/120*ln2^5*Sinf+1/90
         *ln2^6+4*Sinf*li5half-7*li6half-3/4*s6;
Fill Stab6(1,-1,-1,1,-1,-1) =-7/16*z2*z3*ln2-7/16*z2*z3*Sinf+1/
         6*z2*ln2^3*Sinf+5/48*z2*ln2^4+6/5*z2^2*ln2*Sinf+6/5*z2^2*ln2^2
         +27/35*z2^3-7/16*z3*ln2^2*Sinf-7/24*z3*ln2^3+229/128*z3^2-
         81/64*z5*Sinf-1/30*ln2^5*Sinf-7/360*ln2^6+3*Sinf*li5half-9*
         li6half-15/4*s6;
Fill Stab6(1,-1,-1,1,-1,1) =9/16*z2*z3*ln2+9/16*z2*z3*Sinf+1/6*
         z2*ln2^3*Sinf+5/48*z2*ln2^4+6/5*z2^2*ln2*Sinf+6/5*z2^2*ln2^2+
         13/7*z2^3-7/16*z3*ln2^2*Sinf-7/24*z3*ln2^3+165/128*z3^2-9/2*
         z5*ln2-369/64*z5*Sinf-1/30*ln2^5*Sinf-7/360*ln2^6+3*Sinf*
         li5half-9*li6half-15/4*s6;
Fill Stab6(1,-1,-1,1,0,-1) =-1/16*z2*z3*ln2+3/8*z2*z3*Sinf-1/
         12*z2*ln2^3*Sinf-3/16*z2*ln2^4-3/2*z2*li4half+3/5*z2^2*ln2*Sinf
         +113/80*z2^2*ln2^2+86/35*z2^3-1/16*z3*ln2^2*Sinf-1/24*z3*
         ln2^3+97/64*z3^2-279/64*z5*ln2-125/32*z5*Sinf+ln2*Sinf*
         li4half-3*ln2*li5half+1/2*ln2^2*li4half+1/30*ln2^5*Sinf+1/30*
         ln2^6+Sinf*li5half-9*li6half-15/4*s6;
Fill Stab6(1,-1,-1,1,0,1) =-1/16*z2*z3*ln2-15/16*z2*z3*Sinf-1/
         12*z2*ln2^3*Sinf+1/12*z2*ln2^4+3*z2*li4half+3/8*z2^2*ln2*Sinf
         -1/10*z2^2*ln2^2-1/16*z3*ln2^2*Sinf-1/24*z3*ln2^3+63/128*z3^2
         +29/64*z5*Sinf+ln2*Sinf*li4half+1/2*ln2^2*li4half+1/120*ln2^5
         *Sinf+1/144*ln2^6+4*Sinf*li5half-10*li6half;
Fill Stab6(1,-1,-1,1,1,-1) =16/7*z2^3-4*z5*ln2-4*z5*Sinf+ln2*
         Sinf*li4half+1/2*ln2^2*li4half+4*Sinf*li5half-10*li6half;
Fill Stab6(1,-1,-1,1,1,1) =ln2*Sinf*li4half+1/2*ln2^2*li4half+4*
         Sinf*li5half-10*li6half;
Fill Stab6(1,-1,0,-1,-1,-1) =21/16*z2*z3*ln2+21/16*z2*z3*Sinf-17/
         12*z2*ln2^3*Sinf-25/48*z2*ln2^4-1/2*z2*li4half+21/8*z2^2*ln2*
         Sinf+301/80*z2^2*ln2^2+2141/560*z2^3+21/16*z3*ln2^2*Sinf+7/8*
         z3*ln2^3+597/128*z3^2-911/64*z5*Sinf+4*ln2*Sinf*li4half+3/2*
         ln2^2*li4half+7/120*ln2^5*Sinf+1/48*ln2^6+13*Sinf*li5half-30*
         li6half-31/2*s6;
Fill Stab6(1,-1,0,-1,-1,1) =-2/3*z2*ln2^3*Sinf-11/48*z2*ln2^4+
         1/2*z2*li4half+27/8*z2^2*ln2*Sinf+269/80*z2^2*ln2^2+227/80*z2^3
         +39/8*z3^2-911/64*z5*Sinf+4*ln2*Sinf*li4half+3/2*ln2^2*
         li4half+7/120*ln2^5*Sinf+7/240*ln2^6+13*Sinf*li5half-24*
         li6half-13*s6;
Fill Stab6(1,-1,0,-1,0,-1) =5/16*z2*z3*Sinf-1/3*z2*ln2^3*Sinf-11/
         48*z2*ln2^4-3/2*z2*li4half+17/8*z2^2*ln2*Sinf+23/16*z2^2*ln2^2
         +977/1680*z2^3+77/128*z3^2-403/64*z5*ln2-331/32*z5*Sinf+4*
         ln2*Sinf*li4half+4*ln2*li5half+2*ln2^2*li4half+1/10*ln2^5*Sinf
         +1/20*ln2^6+8*Sinf*li5half-3/2*s6;
Fill Stab6(1,-1,0,-1,0,1) =7/4*z2*z3*ln2+9/8*z2*z3*Sinf-2/3*z2*
         ln2^3*Sinf-7/24*z2*ln2^4+3*z2*li4half-7/10*z2^2*ln2*Sinf-11/
         10*z2^2*ln2^2-167/840*z2^3+7/4*z3*ln2^2*Sinf+7/6*z3*ln2^3-3/2
         *z3^2-259/64*z5*Sinf+4*ln2*Sinf*li4half+2*ln2^2*li4half+2/15*
         ln2^5*Sinf+7/90*ln2^6+4*Sinf*li5half-4*li6half+3/4*s6;
Fill Stab6(1,-1,0,-1,1,-1) =3/4*z2*ln2^3*Sinf+11/48*z2*ln2^4+1/
         40*z2^2*ln2*Sinf-45/16*z2^2*ln2^2-16/35*z2^3-45/16*z3^2-279/
         64*z5*ln2-99/32*z5*Sinf+ln2*Sinf*li4half+2*ln2*li5half+1/2*
         ln2^2*li4half+1/60*ln2^5*Sinf+1/60*ln2^6+3*Sinf*li5half+9*
         li6half+15/2*s6;
Fill Stab6(1,-1,0,-1,1,1) =7/16*z2*z3*ln2+7/16*z2*z3*Sinf-1/6*z2
         *ln2^3*Sinf-5/48*z2*ln2^4-6/5*z2^2*ln2*Sinf-3/5*z2^2*ln2^2-6/
         35*z2^3+7/16*z3*ln2^2*Sinf+7/24*z3*ln2^3-229/128*z3^2+81/64*
         z5*Sinf+ln2*Sinf*li4half+1/2*ln2^2*li4half+1/30*ln2^5*Sinf+7/
         360*ln2^6+Sinf*li5half-li6half+15/4*s6;
Fill Stab6(1,-1,0,0,-1,-1) =-39/16*z2*z3*ln2+1/2*z2*ln2^3*Sinf
         +7/24*z2*ln2^4-2/5*z2^2*ln2*Sinf-19/16*z2^2*ln2^2+31/168*z2^3
         -173/64*z3^2-155/32*z5*ln2+15/32*z5*Sinf-2*ln2*Sinf*li4half
         +2*ln2*li5half-ln2^2*li4half-1/12*ln2^5*Sinf-1/20*ln2^6+6*
         li6half+31/4*s6;
Fill Stab6(1,-1,0,0,-1,1) =-7/8*z2*z3*ln2-7/8*z2*z3*Sinf+1/3*
         z2*ln2^3*Sinf+5/24*z2*ln2^4-1/2*z2^2*ln2*Sinf-1/4*z2^2*ln2^2-
         5/6*z2^3-7/8*z3*ln2^2*Sinf-7/12*z3*ln2^3+81/64*z3^2+85/16*z5*
         Sinf-2*ln2*Sinf*li4half-ln2^2*li4half-1/15*ln2^5*Sinf-7/180*
         ln2^6-2*Sinf*li5half+2*li6half+3*s6;
Fill Stab6(1,-1,0,0,0,-1) =-3/4*z2*z3*Sinf+1/12*z2*ln2^4+2*z2*
         li4half-2/5*z2^2*ln2*Sinf-7/10*z2^2*ln2^2-27/35*z2^3+1/4*z3^2
         +91/32*z5*Sinf+5/2*s6;
Fill Stab6(1,-1,0,0,0,1) =3/8*z2*z3*Sinf-1/24*z2*ln2^4-z2*
         li4half+7/20*z2^2*ln2*Sinf+17/40*z2^2*ln2^2+123/140*z2^3-15/
         16*z3^2-155/32*z5*ln2-2*z5*Sinf+s6;
Fill Stab6(1,-1,0,0,1,-1) =39/16*z2*z3*ln2-1/3*z2*ln2^3*Sinf-5/
         24*z2*ln2^4+z2*li4half-13/40*z2^2*ln2*Sinf+23/40*z2^2*ln2^2-
         1139/1680*z2^3+55/128*z3^2+27/8*z5*Sinf+ln2^2*li4half+1/30*
         ln2^5*Sinf+1/24*ln2^6-4*Sinf*li5half-5/2*s6;
Fill Stab6(1,-1,0,0,1,1) =7/8*z2*z3*ln2+7/8*z2*z3*Sinf+1/6*z2*
         ln2^3*Sinf+1/24*z2*ln2^4-z2*li4half+11/10*z2^2*ln2*Sinf+4/5*
         z2^2*ln2^2-893/1680*z2^3-7/8*z3*ln2^2*Sinf-7/12*z3*ln2^3-223/
         128*z3^2-527/64*z5*ln2-311/64*z5*Sinf+6*ln2*li5half+ln2^2*
         li4half-1/60*ln2^5*Sinf+1/360*ln2^6+2*Sinf*li5half+8*li6half
         +3*s6;
Fill Stab6(1,-1,0,1,-1,-1) =-21/16*z2*z3*ln2+7/6*z2*ln2^3*Sinf
         +11/24*z2*ln2^4-81/20*z2^2*ln2*Sinf-87/20*z2^2*ln2^2-3*z2^3
         -7/16*z3*ln2^3-441/64*z3^2-31/32*z5*ln2+245/16*z5*Sinf-4*
         ln2*Sinf*li4half-2*ln2*li5half-2*ln2^2*li4half-1/30*ln2^5*Sinf
         -1/40*ln2^6-16*Sinf*li5half+30*li6half+35/2*s6;
Fill Stab6(1,-1,0,1,-1,1) =-21/8*z2*z3*ln2-21/16*z2*z3*Sinf+7/
         12*z2*ln2^3*Sinf+3/8*z2*ln2^4-49/20*z2^2*ln2*Sinf-29/40*z2^2*
         ln2^2-1041/280*z2^3-21/16*z3*ln2^2*Sinf-21/16*z3*ln2^3-111/
         128*z3^2+521/32*z5*Sinf-4*ln2*Sinf*li4half-2*ln2^2*li4half-1/
         20*ln2^5*Sinf-1/20*ln2^6-14*Sinf*li5half+24*li6half+23/2*s6;
Fill Stab6(1,-1,0,1,0,-1) =-35/8*z2*z3*ln2-3/2*z2*z3*Sinf+2/3*
         z2*ln2^3*Sinf+1/4*z2*ln2^4-4*z2*li4half-13/40*z2^2*ln2*Sinf+
         67/80*z2^2*ln2^2+29/168*z2^3-7/4*z3*ln2^2*Sinf-7/6*z3*ln2^3+
         285/128*z3^2+129/16*z5*Sinf-4*ln2*Sinf*li4half-2*ln2^2*li4half
         -2/15*ln2^5*Sinf-7/90*ln2^6-4*Sinf*li5half+4*li6half+7/2*s6;
Fill Stab6(1,-1,0,1,0,1) =21/16*z2*z3*ln2-1/8*z2*z3*Sinf+1/3*z2*
         ln2^3*Sinf+1/4*z2*ln2^4+2*z2*li4half-51/40*z2^2*ln2*Sinf-91/
         80*z2^2*ln2^2+19/84*z2^3-145/64*z3^2-31/32*z5*ln2+227/32*z5*
         Sinf-4*ln2*Sinf*li4half-4*ln2*li5half-2*ln2^2*li4half-1/10*
         ln2^5*Sinf-1/20*ln2^6-8*Sinf*li5half+5/2*s6;
Fill Stab6(1,-1,0,1,1,-1) =-21/16*z2*z3*Sinf+3/8*z2*ln2^4-3/2*
         z2*li4half+6/5*z2^2*ln2*Sinf+3/2*z2^2*ln2^2+173/560*z2^3-21/
         16*z3*ln2^2*Sinf-21/16*z3*ln2^3+69/32*z3^2+87/32*z5*Sinf-3*
         ln2*Sinf*li4half-3*ln2^2*li4half-1/8*ln2^5*Sinf-31/240*ln2^6-
         3*li6half-9/4*s6;
Fill Stab6(1,-1,0,1,1,1) =35/16*z2*z3*ln2+7/8*z2*z3*Sinf+5/12*z2
         *ln2^3*Sinf+1/2*z2*ln2^4+3/2*z2*li4half-1/8*z2^2*ln2*Sinf-7/
         16*z2^2*ln2^2+163/560*z2^3-7/8*z3*ln2^2*Sinf-49/48*z3*ln2^3-
         209/128*z3^2-93/64*z5*ln2+81/64*z5*Sinf-3*ln2*Sinf*li4half-4*
         ln2*li5half-3*ln2^2*li4half-11/120*ln2^5*Sinf-67/720*ln2^6-4*
         Sinf*li5half-li6half+s6;
Fill Stab6(1,-1,1,-1,-1,-1) =13/8*z2*z3*ln2+13/8*z2*z3*Sinf-5/12
         *z2*ln2^3*Sinf-11/48*z2*ln2^4+1/8*z2^2*ln2*Sinf+1/10*z2^2*ln2^2
         +47/105*z2^3+11/8*z3*ln2^2*Sinf+11/12*z3*ln2^3-13/64*z3^2-
         369/64*z5*Sinf+3*ln2*Sinf*li4half+3/2*ln2^2*li4half+11/120*
         ln2^5*Sinf+37/720*ln2^6+3*Sinf*li5half-3*li6half-3*s6;
Fill Stab6(1,-1,1,-1,-1,1) =-11/8*z2*z3*ln2-11/8*z2*z3*Sinf-5/
         12*z2*ln2^3*Sinf-11/48*z2*ln2^4+1/8*z2^2*ln2*Sinf+1/10*z2^2*
         ln2^2+3/70*z2^3+11/8*z3*ln2^2*Sinf+11/12*z3*ln2^3+83/64*z3^2
         +9/2*z5*ln2-81/64*z5*Sinf+3*ln2*Sinf*li4half+3/2*ln2^2*
         li4half+11/120*ln2^5*Sinf+37/720*ln2^6+3*Sinf*li5half-3*
         li6half-3*s6;
Fill Stab6(1,-1,1,-1,0,-1) =-13/16*z2*z3*ln2-7/8*z2*z3*Sinf-1/
         3*z2*ln2^3*Sinf-13/48*z2*ln2^4+1/20*z2^2*ln2*Sinf+39/80*z2^2*
         ln2^2+389/560*z2^3+13/16*z3*ln2^2*Sinf+13/24*z3*ln2^3+69/32*
         z3^2+93/16*z5*ln2-33/64*z5*Sinf+2*ln2*Sinf*li4half-3*ln2*
         li5half+ln2^2*li4half+3/40*ln2^5*Sinf+1/18*ln2^6+Sinf*li5half
         -8*li6half-11/2*s6;
Fill Stab6(1,-1,1,-1,0,1) =29/16*z2*z3*ln2+31/16*z2*z3*Sinf-1/3*
         z2*ln2^3*Sinf-3/16*z2*ln2^4+1/5*z2^2*ln2*Sinf+19/40*z2^2*ln2^2
         +341/280*z2^3+13/16*z3*ln2^2*Sinf+13/24*z3*ln2^3+89/128*z3^2
         -405/64*z5*Sinf+2*ln2*Sinf*li4half+ln2^2*li4half+1/20*ln2^5*
         Sinf+7/240*ln2^6+4*Sinf*li5half-9*li6half-21/4*s6;
Fill Stab6(1,-1,1,-1,1,-1) =-1/16*z2*z3*ln2-1/16*z2*z3*Sinf+1/
         12*z2*ln2^3*Sinf+1/12*z2*ln2^4-3/8*z2^2*ln2*Sinf-2/5*z2^2*ln2^2
         +1/16*z3*ln2^2*Sinf+1/24*z3*ln2^3+1/128*z3^2+1/2*z5*ln2+3/
         64*z5*Sinf-1/120*ln2^5*Sinf-1/144*ln2^6;
Fill Stab6(1,-1,1,-1,1,1) =15/16*z2*z3*ln2+15/16*z2*z3*Sinf+1/12
         *z2*ln2^3*Sinf+1/12*z2*ln2^4-3/8*z2^2*ln2*Sinf-2/5*z2^2*ln2^2
         +1/16*z3*ln2^2*Sinf+1/24*z3*ln2^3-63/128*z3^2-29/64*z5*Sinf
         -1/120*ln2^5*Sinf-1/144*ln2^6;
Fill Stab6(1,-1,1,0,-1,-1) =1/8*z2*z3*ln2+5/16*z2*z3*Sinf-1/6*z2
         *ln2^3*Sinf+1/16*z2*ln2^4+31/20*z2^2*ln2*Sinf+73/40*z2^2*ln2^2
         +8/5*z2^3-5/16*z3*ln2^2*Sinf-5/24*z3*ln2^3+201/128*z3^2-341/
         64*z5*ln2-457/64*z5*Sinf+4*ln2*li5half-7/120*ln2^5*Sinf-7/144
         *ln2^6+7*Sinf*li5half-11*li6half-17/4*s6;
Fill Stab6(1,-1,1,0,-1,1) =5/16*z2*z3*ln2+5/16*z2*z3*Sinf+1/4*z2
         *ln2^3*Sinf+1/8*z2*ln2^4+9/40*z2^2*ln2*Sinf-3/8*z2^2*ln2^2+
         113/140*z2^3-5/16*z3*ln2^2*Sinf-5/24*z3*ln2^3+47/128*z3^2-29/
         16*z5*Sinf-1/40*ln2^5*Sinf-1/120*ln2^6+3*Sinf*li5half-6*
         li6half-3/4*s6;
Fill Stab6(1,-1,1,0,0,-1) =5/4*z2*z3*ln2+9/8*z2*z3*Sinf-1/6*z2*
         ln2^3*Sinf-1/24*z2*ln2^4+2*z2*li4half+1/5*z2^2*ln2*Sinf-7/20*
         z2^2*ln2^2+13/35*z2^3+1/2*z3*ln2^2*Sinf+1/3*z3*ln2^3-1/8*z3^2
         -153/32*z5*Sinf+2*ln2*Sinf*li4half+ln2^2*li4half+1/20*ln2^5*
         Sinf+1/30*ln2^6+4*Sinf*li5half-6*li6half-3/2*s6;
Fill Stab6(1,-1,1,0,0,1) =-1/2*z2*z3*ln2-7/16*z2*z3*Sinf-1/3*
         z2*ln2^3*Sinf-7/24*z2*ln2^4-z2*li4half+19/40*z2^2*ln2*Sinf+11/
         10*z2^2*ln2^2+31/28*z2^3+1/2*z3*ln2^2*Sinf+1/3*z3*ln2^3+267/
         128*z3^2+155/64*z5*ln2-151/64*z5*Sinf+2*ln2*Sinf*li4half-2*
         ln2*li5half+ln2^2*li4half+1/15*ln2^5*Sinf+17/360*ln2^6+2*Sinf
         *li5half-8*li6half-11/2*s6;
Fill Stab6(1,-1,1,0,1,-1) =11/8*z2*z3*ln2+19/16*z2*z3*Sinf-1/3*
         z2*ln2^3*Sinf-5/12*z2*ln2^4+3/2*z2*li4half-7/5*z2^2*ln2*Sinf-
         121/80*z2^2*ln2^2-479/280*z2^3+23/16*z3*ln2^2*Sinf+23/24*z3*
         ln2^3-177/64*z3^2+35/32*z5*Sinf+3*ln2*Sinf*li4half+3*ln2^2*
         li4half+19/120*ln2^5*Sinf+101/720*ln2^6-4*Sinf*li5half+11*
         li6half+17/4*s6;
Fill Stab6(1,-1,1,0,1,1) =-23/16*z2*z3*ln2-23/16*z2*z3*Sinf-7/
         12*z2*ln2^3*Sinf-23/48*z2*ln2^4-3/2*z2*li4half+1/40*z2^2*ln2*
         Sinf+29/80*z2^2*ln2^2-55/56*z2^3+23/16*z3*ln2^2*Sinf+23/24*z3
         *ln2^3-21/64*z3^2-93/64*z5*ln2-23/64*z5*Sinf+3*ln2*Sinf*
         li4half+6*ln2*li5half+3*ln2^2*li4half+13/120*ln2^5*Sinf+31/
         360*ln2^6+2*Sinf*li5half+8*li6half+5/4*s6;
Fill Stab6(1,-1,1,1,-1,-1) =-1/16*z2*z3*ln2+7/16*z2*z3*Sinf+1/
         6*z2*ln2^3*Sinf+7/48*z2*ln2^4-2/5*z2^2*ln2*Sinf-3/8*z2^2*ln2^2
         +1/60*z2^3-7/16*z3*ln2^2*Sinf-11/24*z3*ln2^3-167/128*z3^2-3
         *z5*ln2+27/32*z5*Sinf-ln2*Sinf*li4half-1/2*ln2^2*li4half-1/30
         *ln2^5*Sinf-17/720*ln2^6-2*Sinf*li5half+3*li6half+3*s6;
Fill Stab6(1,-1,1,1,-1,1) =-17/16*z2*z3*ln2-9/16*z2*z3*Sinf+1/
         6*z2*ln2^3*Sinf+7/48*z2*ln2^4-2/5*z2^2*ln2*Sinf-3/8*z2^2*ln2^2
         -71/140*z2^3-7/16*z3*ln2^2*Sinf-11/24*z3*ln2^3+25/128*z3^2+
         123/32*z5*Sinf-ln2*Sinf*li4half-1/2*ln2^2*li4half-1/30*ln2^5*
         Sinf-17/720*ln2^6-2*Sinf*li5half+3*li6half+3*s6;
Fill Stab6(1,-1,1,1,0,-1) =-11/8*z2*z3*ln2-3/8*z2*z3*Sinf+1/6*
         z2*ln2^3*Sinf+1/12*z2*ln2^4-z2*li4half+1/5*z2^2*ln2*Sinf+29/
         40*z2^2*ln2^2+34/35*z2^3-1/2*z3*ln2^2*Sinf-1/3*z3*ln2^3+7/4*
         z3^2+15/16*z5*Sinf-ln2*Sinf*li4half-1/2*ln2^2*li4half-1/20*
         ln2^5*Sinf-7/240*ln2^6+Sinf*li5half-6*li6half-3/2*s6;
Fill Stab6(1,-1,1,1,0,1) =z2*z3*ln2+1/2*z2*z3*Sinf+1/6*z2*ln2^3*
         Sinf+1/16*z2*ln2^4+1/2*z2*li4half+1/20*z2^2*ln2*Sinf+29/80*
         z2^2*ln2^2+11/14*z2^3-1/2*z3*ln2^2*Sinf-1/3*z3*ln2^3+3/32*
         z3^2-31/32*z5*ln2-1/32*z5*Sinf-ln2*Sinf*li4half-3*ln2*li5half
         -1/2*ln2^2*li4half-1/40*ln2^5*Sinf-1/360*ln2^6-2*Sinf*li5half
         -5*li6half-7/4*s6;
Fill Stab6(1,-1,1,1,1,-1) =1/2*z2*z3*ln2+1/24*z2*ln2^4+1/40*z2^2
         *ln2^2-13/35*z2^3-1/6*z3*ln2^3-1/8*z3^2+z5*Sinf-1/240*ln2^6
         -Sinf*li5half+2*li6half+1/2*s6;
Fill Stab6(1,-1,1,1,1,1) =1/2*z2*z3*ln2+1/24*z2*ln2^4+1/40*z2^2*
         ln2^2-1/5*z2^3-1/6*z3*ln2^3-5/8*z3^2-z5*ln2-1/240*ln2^6-
         Sinf*li5half+2*li6half+1/2*s6;
Fill Stab6(1,0,-1,-1,-1,-1) =21/16*z2*z3*ln2+27/16*z2*z3*Sinf+7/
         12*z2*ln2^3*Sinf-1/4*z2*ln2^4+1/2*z2*li4half-11/8*z2^2*ln2*Sinf
         -29/20*z2^2*ln2^2-431/560*z2^3+21/16*z3*ln2^2*Sinf+7/8*z3*
         ln2^3-269/128*z3^2+101/64*z5*Sinf+1/2*ln2^2*li4half+1/24*
         ln2^5*Sinf+11/360*ln2^6-5*Sinf*li5half+7*li6half+9/4*s6;
Fill Stab6(1,0,-1,-1,-1,1) =-21/16*z2*z3*ln2-21/16*z2*z3*Sinf+
         7/12*z2*ln2^3*Sinf-5/24*z2*ln2^4-1/2*z2*li4half-17/5*z2^2*ln2*
         Sinf-47/40*z2^2*ln2^2+3/560*z2^3+21/16*z3*ln2^2*Sinf+7/8*z3*
         ln2^3+165/128*z3^2+93/8*z5*ln2+845/64*z5*Sinf-3*ln2*Sinf*
         li4half-6*ln2*li5half-ln2^2*li4half-1/30*ln2^5*Sinf+1/240*
         ln2^6-11*Sinf*li5half-3*li6half-3*s6;
Fill Stab6(1,0,-1,-1,0,-1) =-13/16*z2*z3*Sinf+2/3*z2*ln2^3*Sinf
         +11/48*z2*ln2^4+3/2*z2*li4half-17/5*z2^2*ln2*Sinf-3/8*z2^2*
         ln2^2+989/560*z2^3+659/128*z3^2+1457/64*z5*ln2+547/32*z5*Sinf
         -8*ln2*Sinf*li4half-16*ln2*li5half-4*ln2^2*li4half-1/5*ln2^5*
         Sinf-1/15*ln2^6-16*Sinf*li5half-24*li6half-14*s6;
Fill Stab6(1,0,-1,-1,0,1) =25/8*z2*z3*Sinf-1/8*z2*ln2^4-3*z2*
         li4half+3/8*z2^2*ln2*Sinf+3/4*z2^2*ln2^2+31/28*z2^3+1/16*z3^2
         -363/64*z5*Sinf-7/2*s6;
Fill Stab6(1,0,-1,-1,1,-1) =-1/3*z2*ln2^3*Sinf-1/48*z2*ln2^4-
         87/40*z2^2*ln2*Sinf+139/80*z2^2*ln2^2+16/35*z2^3+45/16*z3^2+
         465/64*z5*ln2+221/32*z5*Sinf-ln2*Sinf*li4half-4*ln2*li5half-1/
         2*ln2^2*li4half+1/60*ln2^5*Sinf-7*Sinf*li5half-9*li6half-15/2
         *s6;
Fill Stab6(1,0,-1,-1,1,1) =21/16*z2*z3*Sinf-1/48*z2*ln2^4+9/40*
         z2^2*ln2*Sinf+43/80*z2^2*ln2^2+6/35*z2^3+131/128*z3^2-23/64*
         z5*Sinf+1/40*ln2^5*Sinf+1/720*ln2^6-3*Sinf*li5half+li6half-
         15/4*s6;
Fill Stab6(1,0,-1,0,-1,-1) =15/16*z2*z3*ln2-1/3*z2*ln2^3*Sinf-1/
         12*z2*ln2^4+19/20*z2^2*ln2*Sinf-61/35*z2^3-113/64*z3^2-217/32
         *z5*ln2-123/16*z5*Sinf+4*ln2*Sinf*li4half+8*ln2*li5half+2*
         ln2^2*li4half+1/10*ln2^5*Sinf+1/30*ln2^6+8*Sinf*li5half+12*
         li6half+9/2*s6;
Fill Stab6(1,0,-1,0,-1,1) =15/16*z2*z3*Sinf+17/56*z2^3-115/128*
         z3^2-29/32*z5*Sinf;
Fill Stab6(1,0,-1,0,0,-1) =21/8*z2*z3*Sinf+403/840*z2^3-89/64*
         z3^2-67/16*z5*Sinf;
Fill Stab6(1,0,-1,0,0,1) =-3/4*z2*z3*Sinf-1033/1680*z2^3+69/64
         *z3^2+155/32*z5*ln2+21/32*z5*Sinf-5/2*s6;
Fill Stab6(1,0,-1,0,1,-1) =13/16*z2*z3*ln2+11/8*z2*z3*Sinf-1/3*
         z2*ln2^3*Sinf-1/3*z2*ln2^4+2*z2*li4half-19/20*z2^2*ln2*Sinf-1/
         2*z2^2*ln2^2+87/280*z2^3+7/4*z3*ln2^2*Sinf+7/6*z3*ln2^3-109/
         128*z3^2+33/32*z5*Sinf+2*ln2^2*li4half+1/30*ln2^5*Sinf+7/90*
         ln2^6-4*Sinf*li5half-4*li6half-s6;
Fill Stab6(1,0,-1,0,1,1) =-7/4*z2*z3*ln2-7/4*z2*z3*Sinf-2/3*z2
         *ln2^3*Sinf-7/12*z2*ln2^4-2*z2*li4half+1/2*z2^2*ln2^2-67/70*
         z2^3+7/4*z3*ln2^2*Sinf+7/6*z3*ln2^3-7/128*z3^2-155/64*z5*ln2
         -89/64*z5*Sinf+4*ln2*Sinf*li4half+8*ln2*li5half+4*ln2^2*
         li4half+2/15*ln2^5*Sinf+1/9*ln2^6+4*Sinf*li5half+8*li6half+
         5/4*s6;
Fill Stab6(1,0,-1,1,-1,-1) =-11/12*z2*ln2^3*Sinf-1/24*z2*ln2^4
         +53/40*z2^2*ln2*Sinf+11/16*z2^2*ln2^2+41/280*z2^3-9/32*z3^2
         -341/64*z5*ln2-457/64*z5*Sinf+3*ln2*Sinf*li4half+4*ln2*
         li5half+3/2*ln2^2*li4half+1/15*ln2^5*Sinf+7/240*ln2^6+7*Sinf*
         li5half+3/4*s6;
Fill Stab6(1,0,-1,1,-1,1) =-3/16*z2*z3*Sinf-1/4*z2*ln2^3*Sinf+
         1/24*z2*ln2^4+9/10*z2^2*ln2*Sinf-41/80*z2^2*ln2^2+101/280*z2^3
         -5/128*z3^2-29/16*z5*Sinf-1/40*ln2^5*Sinf-1/360*ln2^6+3*
         Sinf*li5half-2*li6half+1/4*s6;
Fill Stab6(1,0,-1,1,0,-1) =1/16*z2*z3*Sinf+11/280*z2^3+1/128*
         z3^2+5/8*z5*Sinf;
Fill Stab6(1,0,-1,1,0,1) =1/16*z2*z3*Sinf+61/560*z2^3-35/128*
         z3^2-93/64*z5*ln2-53/64*z5*Sinf+3/4*s6;
Fill Stab6(1,0,-1,1,1,-1) =7/16*z2*z3*ln2+7/16*z2*z3*Sinf+1/6*z2
         *ln2^3*Sinf-5/48*z2*ln2^4+1/2*z2*li4half-1/20*z2^2*ln2*Sinf-3/
         20*z2^2*ln2^2-17/280*z2^3+7/16*z3*ln2^2*Sinf+7/24*z3*ln2^3-49/
         128*z3^2+1/8*z5*Sinf+1/2*ln2^2*li4half+1/120*ln2^5*Sinf+1/48*
         ln2^6-Sinf*li5half;
Fill Stab6(1,0,-1,1,1,1) =-7/16*z2*z3*ln2-7/16*z2*z3*Sinf-1/6*
         z2*ln2^3*Sinf-7/48*z2*ln2^4-1/2*z2*li4half+1/8*z2^2*ln2^2-9/
         40*z2^3+7/16*z3*ln2^2*Sinf+7/24*z3*ln2^3-17/128*z3^2-31/32*z5
         *ln2-27/32*z5*Sinf+ln2*Sinf*li4half+2*ln2*li5half+ln2^2*
         li4half+1/30*ln2^5*Sinf+1/36*ln2^6+Sinf*li5half+2*li6half+1/
         2*s6;
Fill Stab6(1,0,0,-1,-1,-1) =-7/8*z2*z3*ln2-1/2*z2*z3*Sinf-1/2*
         z2*ln2^3*Sinf-1/24*z2*ln2^4-19/40*z2^2*ln2*Sinf+17/20*z2^2*
         ln2^2+4/5*z2^3-7/24*z3*ln2^3-3/4*z3^2-155/32*z5*ln2+15/32*
         z5*Sinf+2*ln2*Sinf*li4half+2*ln2*li5half+ln2^2*li4half+1/12*
         ln2^5*Sinf+1/45*ln2^6-2*li6half+5/4*s6;
Fill Stab6(1,0,0,-1,-1,1) =-7/8*z2*z3*ln2-13/8*z2*z3*Sinf-1/6*
         z2*ln2^3*Sinf+1/24*z2*ln2^4-1/10*z2^2*ln2*Sinf+17/40*z2^2*ln2^2
         -9/28*z2^3-7/24*z3*ln2^3+81/32*z3^2+85/16*z5*Sinf+1/60*
         ln2^5*Sinf-1/360*ln2^6-2*Sinf*li5half-2*li6half-1/2*s6;
Fill Stab6(1,0,0,-1,0,-1) =-7/4*z2*z3*ln2-9/4*z2*z3*Sinf-1/12*
         z2*ln2^4-2*z2*li4half+1/2*z2^2*ln2^2-13/420*z2^3+163/64*z3^2
         +83/16*z5*Sinf;
Fill Stab6(1,0,0,-1,0,1) =7/8*z2*z3*ln2-5/8*z2*z3*Sinf+1/24*z2*
         ln2^4+z2*li4half-1/4*z2^2*ln2^2+179/420*z2^3-121/64*z3^2-
         155/32*z5*ln2+11/32*z5*Sinf+5/2*s6;
Fill Stab6(1,0,0,-1,1,-1) =-3/4*z2*z3*Sinf+1/3*z2*ln2^3*Sinf+7/
         24*z2*ln2^4-2*z2*li4half+17/10*z2^2*ln2*Sinf+3/40*z2^2*ln2^2-
         19/35*z2^3-7/8*z3*ln2^2*Sinf-7/8*z3*ln2^3+1/4*z3^2-39/16*z5*
         Sinf-2*ln2^2*li4half-1/30*ln2^5*Sinf-3/40*ln2^6+4*Sinf*
         li5half+6*li6half+3/2*s6;
Fill Stab6(1,0,0,-1,1,1) =7/4*z2*z3*ln2+3/8*z2*z3*Sinf+1/3*z2*
         ln2^3*Sinf+11/24*z2*ln2^4+2*z2*li4half-1/2*z2^2*ln2^2+19/35*
         z2^3-7/8*z3*ln2^2*Sinf-7/8*z3*ln2^3-3/8*z3^2+93/32*z5*ln2+
         15/32*z5*Sinf-2*ln2*Sinf*li4half-6*ln2*li5half-3*ln2^2*li4half
         -1/15*ln2^5*Sinf-1/12*ln2^6-2*Sinf*li5half-6*li6half-3/2*s6;
Fill Stab6(1,0,0,0,-1,-1) =3/2*z2*z3*ln2+3/4*z2*z3*Sinf+3/4*z2^2
         *ln2*Sinf-71/840*z2^3-1/8*z3^2-59/32*z5*Sinf-3/2*s6;
Fill Stab6(1,0,0,0,-1,1) =1/2*z2*z3*Sinf+11/168*z2^3-1/4*z3^2-
         59/32*z5*Sinf;
Fill Stab6(1,0,0,0,0,-1) =23/70*z2^3-3/4*z3^2-31/16*z5*ln2-15/
         16*z5*Sinf+s6;
Fill Stab6(1,0,0,0,0,1) =-6/35*z2^3+1/2*z3^2+z5*Sinf;
Fill Stab6(1,0,0,0,1,-1) =-3/2*z2*z3*ln2-3/8*z2*z3*Sinf-3/4*
         z2^2*ln2*Sinf+43/84*z2^3-55/64*z3^2-31/16*z5*ln2+17/16*z5*
         Sinf+5/2*s6;
Fill Stab6(1,0,0,0,1,1) =-z2*z3*Sinf-11/21*z2^3+3/2*z3^2+3*
         z5*Sinf;
Fill Stab6(1,0,0,1,-1,-1) =7/8*z2*z3*ln2+15/8*z2*z3*Sinf+1/6*z2*
         ln2^3*Sinf-1/12*z2*ln2^4+19/40*z2^2*ln2*Sinf-17/20*z2^2*ln2^2
         -23/80*z2^3+7/8*z3*ln2^2*Sinf+7/12*z3*ln2^3-111/64*z3^2-311/
         64*z5*Sinf-1/60*ln2^5*Sinf+1/180*ln2^6+2*Sinf*li5half+4*
         li6half+5/4*s6;
Fill Stab6(1,0,0,1,-1,1) =-7/8*z2*z3*ln2-1/16*z2*z3*Sinf+1/6*
         z2*ln2^3*Sinf-1/12*z2*ln2^4-49/40*z2^2*ln2*Sinf-17/40*z2^2*
         ln2^2+97/112*z2^3+7/8*z3*ln2^2*Sinf+7/12*z3*ln2^3+243/128*
         z3^2+527/64*z5*ln2+27/8*z5*Sinf-2*ln2*Sinf*li4half-6*ln2*
         li5half-ln2^2*li4half-1/20*ln2^5*Sinf-1/360*ln2^6-4*Sinf*
         li5half-8*li6half-9/2*s6;
Fill Stab6(1,0,0,1,0,-1) =1/4*z2*z3*Sinf-59/210*z2^3+19/32*z3^2
         +93/32*z5*ln2-51/32*z5*Sinf-3/2*s6;
Fill Stab6(1,0,0,1,0,1) =3*z2*z3*Sinf+17/42*z2^3-3/2*z3^2-9/2*
         z5*Sinf;
Fill Stab6(1,0,0,1,1,-1) =-1/16*z2*z3*Sinf-1/3*z2*ln2^3*Sinf-1/
         12*z2*ln2^4-3/8*z2^2*ln2*Sinf+17/40*z2^2*ln2^2-1/128*z3^2-93/
         64*z5*ln2-125/64*z5*Sinf+2*ln2*Sinf*li4half+2*ln2*li5half+
         ln2^2*li4half+1/15*ln2^5*Sinf+1/40*ln2^6+2*Sinf*li5half;
Fill Stab6(1,0,0,1,1,1) =z2*z3*Sinf-1/2*z3^2-1/2*z5*Sinf;
Fill Stab6(1,0,1,-1,-1,-1) =-7/8*z2*z3*ln2-3/8*z2*z3*Sinf-13/
         12*z2*ln2^3*Sinf+1/48*z2*ln2^4+11/8*z2^2*ln2*Sinf+53/40*z2^2*
         ln2^2+34/35*z2^3-7/24*z3*ln2^3-25/64*z3^2-93/16*z5*ln2-61/8
         *z5*Sinf+3*ln2*Sinf*li4half+4*ln2*li5half+3/2*ln2^2*li4half+7/
         120*ln2^5*Sinf+1/40*ln2^6+8*Sinf*li5half-3*li6half+3/4*s6;
Fill Stab6(1,0,1,-1,-1,1) =-7/8*z2*z3*ln2-5/12*z2*ln2^3*Sinf+5/
         48*z2*ln2^4+19/20*z2^2*ln2*Sinf+1/8*z2^2*ln2^2-7/24*z3*ln2^3+
         49/32*z3^2-29/16*z5*Sinf-1/30*ln2^5*Sinf-1/144*ln2^6+4*Sinf*
         li5half-5*li6half;
Fill Stab6(1,0,1,-1,0,-1) =-7/4*z2*z3*ln2-z2*z3*Sinf+1/24*z2*
         ln2^4+z2*li4half-3/8*z2^2*ln2*Sinf-1/4*z2^2*ln2^2-43/56*z2^3
         +39/64*z3^2+257/64*z5*Sinf+7/2*s6;
Fill Stab6(1,0,1,-1,0,1) =7/8*z2*z3*ln2-z2*z3*Sinf-2/3*z2*ln2^3*
         Sinf-3/16*z2*ln2^4-1/2*z2*li4half+17/5*z2^2*ln2*Sinf+1/8*z2^2
         *ln2^2-1213/560*z2^3-81/16*z3^2-1271/64*z5*ln2-507/32*z5*Sinf
         +8*ln2*Sinf*li4half+16*ln2*li5half+4*ln2^2*li4half+1/5*ln2^5*
         Sinf+1/15*ln2^6+16*Sinf*li5half+24*li6half+25/2*s6;
Fill Stab6(1,0,1,-1,1,-1) =-7/16*z2*z3*ln2-21/16*z2*z3*Sinf+1/
         3*z2*ln2^3*Sinf+7/24*z2*ln2^4-3/2*z2*li4half+83/40*z2^2*ln2*
         Sinf+79/80*z2^2*ln2^2-163/560*z2^3-21/16*z3*ln2^2*Sinf-7/6*z3
         *ln2^3+209/128*z3^2-85/64*z5*Sinf-3/2*ln2^2*li4half-1/30*
         ln2^5*Sinf-11/180*ln2^6+4*Sinf*li5half+li6half-s6;
Fill Stab6(1,0,1,-1,1,1) =35/16*z2*z3*ln2+5/12*z2*ln2^4+3/2*z2*
         li4half+17/8*z2^2*ln2*Sinf+21/80*z2^2*ln2^2-173/560*z2^3-21/
         16*z3*ln2^2*Sinf-7/6*z3*ln2^3-89/64*z3^2-403/64*z5*ln2-61/8*
         z5*Sinf+ln2*Sinf*li4half+2*ln2*li5half-ln2^2*li4half-1/120*
         ln2^5*Sinf-13/240*ln2^6+6*Sinf*li5half+3*li6half+9/4*s6;
Fill Stab6(1,0,1,0,-1,-1) =5/4*z2*z3*ln2-7/4*z2*z3*Sinf+1/3*z2*
         ln2^3*Sinf+1/3*z2*ln2^4-2*z2*li4half+113/40*z2^2*ln2*Sinf+1/2
         *z2^2*ln2^2-411/560*z2^3-7/4*z3*ln2^2*Sinf-7/6*z3*ln2^3+7/4*
         z3^2-89/64*z5*Sinf-2*ln2^2*li4half-1/30*ln2^5*Sinf-7/90*ln2^6
         +4*Sinf*li5half+4*li6half-9/4*s6;
Fill Stab6(1,0,1,0,-1,1) =7/4*z2*z3*ln2+13/16*z2*z3*Sinf+2/3*z2*
         ln2^3*Sinf+7/12*z2*ln2^4+2*z2*li4half-1/2*z2^2*ln2^2+93/80*
         z2^3-7/4*z3*ln2^2*Sinf-7/6*z3*ln2^3-13/128*z3^2+155/64*z5*ln2
         +33/32*z5*Sinf-4*ln2*Sinf*li4half-8*ln2*li5half-4*ln2^2*
         li4half-2/15*ln2^5*Sinf-1/9*ln2^6-4*Sinf*li5half-8*li6half-
         5/4*s6;
Fill Stab6(1,0,1,0,0,-1) =-1/8*z2*z3*Sinf+13/12*z2^3-103/64*
         z3^2-217/32*z5*ln2-41/32*z5*Sinf+7/2*s6;
Fill Stab6(1,0,1,0,0,1) =-2*z2*z3*Sinf-29/30*z2^3+2*z3^2+11/
         2*z5*Sinf;
Fill Stab6(1,0,1,0,1,-1) =-3*z2*z3*ln2+3/8*z2*z3*Sinf+1/3*z2*
         ln2^3*Sinf+1/12*z2*ln2^4-113/40*z2^2*ln2*Sinf+86/35*z2^3+27/
         64*z3^2+93/16*z5*ln2+125/16*z5*Sinf-4*ln2*Sinf*li4half-8*ln2*
         li5half-2*ln2^2*li4half-1/10*ln2^5*Sinf-1/30*ln2^6-8*Sinf*
         li5half-12*li6half-3/4*s6;
Fill Stab6(1,0,1,0,1,1) =-8/7*z2^3+2*z3^2+2*z5*Sinf;
Fill Stab6(1,0,1,1,-1,-1) =-7/16*z2*z3*ln2-7/16*z2*z3*Sinf+11/
         12*z2*ln2^3*Sinf+5/48*z2*ln2^4-3/2*z2*li4half+49/40*z2^2*ln2*
         Sinf-119/80*z2^2*ln2^2-48/35*z2^3-7/16*z3*ln2^2*Sinf-7/24*z3*
         ln2^3-131/128*z3^2-23/64*z5*Sinf-3/2*ln2^2*li4half-1/60*ln2^5
         *Sinf-7/144*ln2^6+2*Sinf*li5half+10*li6half+15/4*s6;
Fill Stab6(1,0,1,1,-1,1) =7/16*z2*z3*ln2+5/8*z2*z3*Sinf+11/12*z2
         *ln2^3*Sinf+5/16*z2*ln2^4+3/2*z2*li4half-4/5*z2^2*ln2*Sinf-
         177/80*z2^2*ln2^2+4/5*z2^3-7/16*z3*ln2^2*Sinf-7/24*z3*ln2^3-
         97/64*z3^2+93/64*z5*ln2+35/32*z5*Sinf-3*ln2*Sinf*li4half-6*
         ln2*li5half-3*ln2^2*li4half-11/120*ln2^5*Sinf-3/40*ln2^6-4*
         Sinf*li5half+15/4*s6;
Fill Stab6(1,0,1,1,0,-1) =5/16*z2*z3*Sinf+7/5*z2^3-165/128*z3^2
         -465/64*z5*ln2-177/64*z5*Sinf+15/4*s6;
Fill Stab6(1,0,1,1,0,1) =-z2*z3*Sinf-38/35*z2^3+1/2*z3^2+9/2
         *z5*Sinf;
Fill Stab6(1,0,1,1,1,-1) =-1/3*z2*ln2^3*Sinf-12/5*z2^2*ln2*Sinf
         +6/5*z2^2*ln2^2+16/7*z2^3+4*z5*Sinf-ln2*Sinf*li4half-4*ln2*
         li5half-1/2*ln2^2*li4half-1/120*ln2^5*Sinf-1/720*ln2^6-4*Sinf
         *li5half-10*li6half;
Fill Stab6(1,0,1,1,1,1) =-16/7*z2^3+4*z5*Sinf;
Fill Stab6(1,1,-1,-1,-1,-1) =9/8*z2*z3*ln2+z2*z3*Sinf+1/8*z2*
         ln2^2*Sinf^2-39/40*z2^2*ln2*Sinf-77/80*z2^2*ln2^2+9/80*z2^2*
         Sinf^2-61/112*z2^3+1/8*z3*ln2*Sinf^2+9/8*z3*ln2^2*Sinf+17/24*
         z3*ln2^3-55/32*z3^2+23/64*z5*Sinf+1/48*ln2^4*Sinf^2+7/120*
         ln2^5*Sinf+17/720*ln2^6-3*Sinf*li5half+7*li6half+9/4*s6;
Fill Stab6(1,1,-1,-1,-1,1) =-7/8*z2*z3*ln2-z2*z3*Sinf+1/8*z2*
         ln2^2*Sinf^2-67/40*z2^2*ln2*Sinf-21/16*z2^2*ln2^2-19/80*z2^2*
         Sinf^2-2687/1680*z2^3+1/8*z3*ln2*Sinf^2+9/8*z3*ln2^2*Sinf+17/
         24*z3*ln2^3-23/32*z3^2+11/2*z5*ln2+375/64*z5*Sinf+1/48*ln2^4*
         Sinf^2+7/120*ln2^5*Sinf+17/720*ln2^6-3*Sinf*li5half+7*li6half
         +9/4*s6;
Fill Stab6(1,1,-1,-1,0,-1) =1/2*z2*z3*ln2-7/8*z2*z3*Sinf-1/8*z2*
         ln2^2*Sinf^2+1/6*z2*ln2^3*Sinf+1/4*z2*ln2^4+3/2*z2*li4half-59/
         40*z2^2*ln2*Sinf-15/8*z2^2*ln2^2-3/10*z2^2*Sinf^2-193/70*z2^3
         +1/2*z3*ln2*Sinf^2+1/2*z3*ln2^2*Sinf+1/6*z3*ln2^3-73/64*z3^2
         +465/64*z5*ln2+247/32*z5*Sinf-3*ln2*Sinf*li4half+ln2*li5half
         -3/2*ln2^2*li4half-1/12*ln2^5*Sinf-41/720*ln2^6-5*Sinf*
         li5half+10*li6half+11/4*s6;
Fill Stab6(1,1,-1,-1,0,1) =1/2*z2*z3*ln2+7/4*z2*z3*Sinf-1/8*z2*
         ln2^2*Sinf^2-1/6*z2*ln2^3*Sinf-1/8*z2*ln2^4-3/2*z2*li4half-37/
         40*z2^2*ln2*Sinf+7/80*z2^2*ln2^2-3/16*z2^2*Sinf^2-137/560*z2^3
         +1/2*z3*ln2*Sinf^2+1/2*z3*ln2^2*Sinf+1/6*z3*ln2^3-31/32*z3^2
         +29/64*z5*Sinf+1/16*ln2^4*Sinf^2+1/20*ln2^5*Sinf+1/80*ln2^6
         -6*Sinf*li5half+3/2*Sinf^2*li4half+9*li6half+1/4*s6;
Fill Stab6(1,1,-1,-1,1,-1) =7/16*z2*z3*ln2-1/4*z2*ln2^2*Sinf^2-1/
         4*z2*ln2^3*Sinf+3/2*z2*li4half-6/5*z2^2*ln2*Sinf-17/20*z2^2*
         ln2^2-3/5*z2^2*Sinf^2-101/35*z2^3+7/16*z3*ln2*Sinf^2+7/16*z3*
         ln2^2*Sinf+7/48*z3*ln2^3+6*z5*ln2+6*z5*Sinf+1/12*ln2^4*Sinf^2
         +1/12*ln2^5*Sinf+1/36*ln2^6-6*Sinf*li5half+3/2*Sinf^2*li4half
         +10*li6half;
Fill Stab6(1,1,-1,-1,1,1) =7/16*z2*z3*ln2-1/4*z2*ln2^2*Sinf^2-1/
         4*z2*ln2^3*Sinf+3/2*z2*li4half-1/4*z2^2*ln2^2+7/16*z3*ln2*
         Sinf^2+7/16*z3*ln2^2*Sinf+7/48*z3*ln2^3+1/12*ln2^4*Sinf^2+1/
         12*ln2^5*Sinf+1/36*ln2^6-6*Sinf*li5half+3/2*Sinf^2*li4half+10
         *li6half;
Fill Stab6(1,1,-1,0,-1,-1) =13/8*z2*z3*ln2+1/4*z2*ln2^2*Sinf^2-1/
         12*z2*ln2^3*Sinf-1/12*z2*ln2^4+2*z2*li4half-91/40*z2^2*ln2*Sinf
         +3/40*z2^2*ln2^2-7/10*z2^2*Sinf^2-17/14*z2^3+5/16*z3*ln2*
         Sinf^2+5/16*z3*ln2^2*Sinf+5/48*z3*ln2^3+107/64*z3^2+465/64*z5
         *ln2+221/32*z5*Sinf+ln2*Sinf*li4half-4*ln2*li5half+1/2*ln2^2*
         li4half+1/12*ln2^4*Sinf^2+1/10*ln2^5*Sinf+37/720*ln2^6-7*Sinf
         *li5half+2*Sinf^2*li4half-2*li6half-19/4*s6;
Fill Stab6(1,1,-1,0,-1,1) =5/16*z2*z3*ln2-3/8*z2*ln2^2*Sinf^2-1/
         4*z2*ln2^3*Sinf+3/2*z2*li4half+39/40*z2^2*ln2*Sinf+9/80*z2^2*
         ln2^2-9/80*z2^2*Sinf^2-31/560*z2^3+5/16*z3*ln2*Sinf^2+5/16*z3
         *ln2^2*Sinf+5/48*z3*ln2^3-1/32*z3^2-23/64*z5*Sinf+1/16*ln2^4*
         Sinf^2+1/40*ln2^5*Sinf+1/240*ln2^6-3*Sinf*li5half+3/2*Sinf^2*
         li4half+3*li6half-9/4*s6;
Fill Stab6(1,1,-1,0,0,-1) =3/8*z2*z3*ln2+13/8*z2*z3*Sinf-1/4*z2*
         ln2^2*Sinf^2-1/6*z2*ln2^3*Sinf-1/8*z2*ln2^4-2*z2*li4half-1/10
         *z2^2*ln2*Sinf+9/20*z2^2*ln2^2-1/10*z2^2*Sinf^2+93/140*z2^3+3/
         8*z3*ln2*Sinf^2+3/8*z3*ln2^2*Sinf+1/8*z3*ln2^3-1/2*z3^2-15/8*
         z5*Sinf+1/24*ln2^4*Sinf^2+1/60*ln2^5*Sinf+1/360*ln2^6-2*Sinf*
         li5half+Sinf^2*li4half+2*li6half-2*s6;
Fill Stab6(1,1,-1,0,0,1) =3/8*z2*z3*ln2-13/16*z2*z3*Sinf+1/6*z2*
         ln2^3*Sinf+7/48*z2*ln2^4+3/2*z2*li4half-49/40*z2^2*ln2*Sinf-
         79/80*z2^2*ln2^2-19/80*z2^2*Sinf^2-691/560*z2^3+3/8*z3*ln2*
         Sinf^2+3/8*z3*ln2^2*Sinf+1/8*z3*ln2^3+101/128*z3^2+31/4*z5*
         ln2+47/8*z5*Sinf-2*ln2*Sinf*li4half-2*ln2*li5half-ln2^2*
         li4half-1/20*ln2^5*Sinf-1/40*ln2^6-4*Sinf*li5half-3/2*s6;
Fill Stab6(1,1,-1,0,1,-1) =-1/8*z2*z3*ln2+21/16*z2*z3*Sinf-1/4
         *z2*ln2^2*Sinf^2-1/4*z2*ln2^3*Sinf-7/48*z2*ln2^4-5/2*z2*li4half
         +21/20*z2^2*ln2*Sinf-9/16*z2^2*ln2^2+5/8*z2^2*Sinf^2+909/560*
         z2^3-1/8*z3*ln2*Sinf^2+19/16*z3*ln2^2*Sinf+5/6*z3*ln2^3-1/2*
         z3^2-61/8*z5*Sinf-1/2*ln2^2*li4half-1/12*ln2^4*Sinf^2-1/20*
         ln2^5*Sinf-19/720*ln2^6+6*Sinf*li5half-2*Sinf^2*li4half-4*
         li6half-s6;
Fill Stab6(1,1,-1,0,1,1) =-23/16*z2*z3*ln2-21/16*z2*z3*Sinf+1/
         8*z2*ln2^2*Sinf^2-5/12*z2*ln2^3*Sinf-13/48*z2*ln2^4+1/20*z2^2*
         ln2*Sinf+1/40*z2^2*ln2^2-1/80*z2^2*Sinf^2+109/280*z2^3-1/8*z3
         *ln2*Sinf^2+19/16*z3*ln2^2*Sinf+5/6*z3*ln2^3+31/16*z3^2+403/
         64*z5*ln2-85/64*z5*Sinf+3*ln2*Sinf*li4half-2*ln2*li5half+
         ln2^2*li4half-1/48*ln2^4*Sinf^2+11/120*ln2^5*Sinf+7/144*ln2^6
         +4*Sinf*li5half-1/2*Sinf^2*li4half-7*li6half-4*s6;
Fill Stab6(1,1,-1,1,-1,-1) =7/16*z2*z3*ln2-1/8*z2*ln2^2*Sinf^2-1/
         4*z2*ln2^3*Sinf-1/8*z2*ln2^4-3/40*z2^2*ln2*Sinf-27/80*z2^2*
         ln2^2-1/16*z2^2*Sinf^2-649/1680*z2^3-1/16*z3*ln2*Sinf^2-1/16*
         z3*ln2^2*Sinf+7/48*z3*ln2^3+7/32*z3^2+1/2*z5*ln2+3/64*z5*Sinf
         +1/48*ln2^4*Sinf^2+1/30*ln2^5*Sinf+11/720*ln2^6+li6half-1/4
         *s6;
Fill Stab6(1,1,-1,1,-1,1) =7/16*z2*z3*ln2-1/8*z2*ln2^2*Sinf^2-1/
         4*z2*ln2^3*Sinf-1/8*z2*ln2^4+17/40*z2^2*ln2*Sinf-7/80*z2^2*
         ln2^2+3/16*z2^2*Sinf^2+137/560*z2^3-1/16*z3*ln2*Sinf^2-1/16*
         z3*ln2^2*Sinf+7/48*z3*ln2^3-25/32*z3^2-29/64*z5*Sinf+1/48*
         ln2^4*Sinf^2+1/30*ln2^5*Sinf+11/720*ln2^6+li6half-1/4*s6;
Fill Stab6(1,1,-1,1,0,-1) =17/16*z2*z3*ln2+1/8*z2*z3*Sinf-1/12*
         z2*ln2^3*Sinf+z2*li4half-3/4*z2^2*ln2*Sinf-9/20*z2^2*ln2^2-1/
         10*z2^2*Sinf^2-151/140*z2^3+1/16*z3*ln2*Sinf^2+1/16*z3*ln2^2*
         Sinf+1/48*z3*ln2^3-13/8*z3^2+123/32*z5*Sinf+1/24*ln2^4*Sinf^2
         +1/24*ln2^5*Sinf+1/90*ln2^6-5*Sinf*li5half+Sinf^2*li4half+8
         *li6half+2*s6;
Fill Stab6(1,1,-1,1,0,1) =-7/16*z2*z3*ln2-1/16*z2*z3*Sinf+1/4*
         z2*ln2^3*Sinf+3/16*z2*ln2^4-1/2*z2*li4half-37/40*z2^2*ln2*Sinf
         -11/10*z2^2*ln2^2-1/40*z2^2*Sinf^2-181/140*z2^3+1/16*z3*ln2*
         Sinf^2+1/16*z3*ln2^2*Sinf+1/48*z3*ln2^3-153/128*z3^2+31/64*z5
         *ln2+277/64*z5*Sinf-3*ln2*Sinf*li4half+ln2*li5half-3/2*ln2^2*
         li4half-1/48*ln2^4*Sinf^2-11/120*ln2^5*Sinf-7/120*ln2^6-4*
         Sinf*li5half-1/2*Sinf^2*li4half+9*li6half+9/2*s6;
Fill Stab6(1,1,-1,1,1,-1) =1/2*z2*z3*Sinf-1/6*z2*ln2^3*Sinf-1/8*
         z2*ln2^4-1/2*z2*li4half+7/20*z2^2*ln2*Sinf-1/20*z2^2*ln2^2+1/
         5*z2^2*Sinf^2+51/140*z2^3+1/2*z3*ln2^2*Sinf+1/2*z3*ln2^3-1/2*
         z3^2-63/32*z5*Sinf+1/40*ln2^5*Sinf+1/72*ln2^6+Sinf*li5half-
         1/2*Sinf^2*li4half;
Fill Stab6(1,1,-1,1,1,1) =-z2*z3*ln2-1/2*z2*z3*Sinf-1/6*z2*
         ln2^3*Sinf-1/8*z2*ln2^4-1/2*z2*li4half-1/20*z2^2*ln2*Sinf-1/4
         *z2^2*ln2^2-23/140*z2^3+1/2*z3*ln2^2*Sinf+1/2*z3*ln2^3+1/2*
         z3^2+2*z5*ln2+1/32*z5*Sinf+1/40*ln2^5*Sinf+1/72*ln2^6+Sinf*
         li5half-1/2*Sinf^2*li4half;
Fill Stab6(1,1,0,-1,-1,-1) =-7/8*z2*z3*ln2-1/4*z2*ln2^2*Sinf^2
         +1/2*z2*ln2^3*Sinf+1/16*z2*ln2^4-2*z2*li4half+53/40*z2^2*ln2*
         Sinf-21/20*z2^2*ln2^2+7/10*z2^2*Sinf^2+1/14*z2^3-21/16*z3*ln2
         *Sinf^2-21/16*z3*ln2^2*Sinf-7/24*z3*ln2^3-107/64*z3^2-279/64*
         z5*ln2-99/32*z5*Sinf-ln2*Sinf*li4half+2*ln2*li5half-1/2*ln2^2
         *li4half-1/12*ln2^4*Sinf^2-1/15*ln2^5*Sinf-1/36*ln2^6+3*Sinf*
         li5half-2*Sinf^2*li4half+7*li6half+19/4*s6;
Fill Stab6(1,1,0,-1,-1,1) =7/16*z2*z3*ln2+1/12*z2*ln2^3*Sinf-1/
         12*z2*ln2^4-3/2*z2*li4half-43/40*z2^2*ln2*Sinf-2/5*z2^2*ln2^2
         +39/80*z2^2*Sinf^2+209/560*z2^3+7/48*z3*ln2^3-109/64*z3^2+
         81/64*z5*Sinf-1/16*ln2^4*Sinf^2-1/120*ln2^5*Sinf+1/720*ln2^6+
         Sinf*li5half-3/2*Sinf^2*li4half+li6half+5/2*s6;
Fill Stab6(1,1,0,-1,0,-1) =7/8*z2*z3*ln2-5/8*z2*z3*Sinf+1/24*z2*
         ln2^4+z2*li4half-1/4*z2^2*ln2^2+13/80*z2^2*Sinf^2-157/1680*
         z2^3-51/128*z3^2+41/32*z5*Sinf;
Fill Stab6(1,1,0,-1,0,1) =-35/16*z2*z3*ln2+5/16*z2*z3*Sinf+1/2
         *z2*ln2^2*Sinf^2+2/3*z2*ln2^3*Sinf+7/48*z2*ln2^4-5/2*z2*li4half
         +5/8*z2^2*ln2^2+51/80*z2^2*Sinf^2+1153/840*z2^3-7/4*z3*ln2*
         Sinf^2-7/4*z3*ln2^2*Sinf-7/12*z3*ln2^3+109/128*z3^2+31/16*z5*
         ln2+103/32*z5*Sinf-4*ln2*Sinf*li4half-4*ln2*li5half-2*ln2^2*
         li4half-1/12*ln2^4*Sinf^2-2/15*ln2^5*Sinf-1/18*ln2^6-4*Sinf*
         li5half-2*Sinf^2*li4half-4*li6half-s6;
Fill Stab6(1,1,0,-1,1,-1) =-7/16*z2*z3*ln2+3/8*z2*ln2^2*Sinf^2
         -1/12*z2*ln2^3*Sinf-1/16*z2*ln2^4+1/2*z2*li4half-1/20*z2^2*
         ln2*Sinf+13/20*z2^2*ln2^2+3/80*z2^2*Sinf^2+21/80*z2^3+7/48*z3
         *ln2^3+17/128*z3^2+25/32*z5*Sinf+1/2*ln2^2*li4half+1/120*
         ln2^5*Sinf+13/720*ln2^6-Sinf*li5half-2*li6half-1/2*s6;
Fill Stab6(1,1,0,-1,1,1) =-7/8*z2*z3*ln2+1/8*z2*ln2^2*Sinf^2+1/
         6*z2*ln2^3*Sinf-1/24*z2*ln2^4-z2*li4half+1/4*z2^2*ln2^2+1/16*
         z2^2*Sinf^2+69/560*z2^3-7/16*z3*ln2*Sinf^2-7/16*z3*ln2^2*Sinf
         +49/128*z3^2+25/32*z5*Sinf-ln2*Sinf*li4half-1/48*ln2^4*Sinf^2
         -1/30*ln2^5*Sinf-Sinf*li5half-1/2*Sinf^2*li4half;
Fill Stab6(1,1,0,0,-1,-1) =-5/8*z2*z3*ln2+7/8*z2*z3*Sinf+1/4*
         z2*ln2^2*Sinf^2-1/6*z2*ln2^3*Sinf-5/24*z2*ln2^4-17/20*z2^2*ln2*
         Sinf+3/10*z2^2*Sinf^2+509/840*z2^3+7/8*z3*ln2^2*Sinf+7/12*z3*
         ln2^3-41/64*z3^2+15/32*z5*Sinf+ln2^2*li4half-1/24*ln2^4*
         Sinf^2+1/60*ln2^5*Sinf+7/180*ln2^6-2*Sinf*li5half-Sinf^2*
         li4half-2*li6half+1/2*s6;
Fill Stab6(1,1,0,0,-1,1) =-7/8*z2*z3*Sinf-1/4*z2*ln2^2*Sinf^2-
         2/3*z2*ln2^3*Sinf-3/8*z2*ln2^4-11/20*z2^2*Sinf^2-227/168*z2^3
         +7/8*z3*ln2*Sinf^2+7/4*z3*ln2^2*Sinf+7/8*z3*ln2^3-9/64*z3^2
         -93/32*z5*ln2-39/16*z5*Sinf+4*ln2*Sinf*li4half+6*ln2*li5half
         +3*ln2^2*li4half+1/24*ln2^4*Sinf^2+2/15*ln2^5*Sinf+1/12*ln2^6
         +4*Sinf*li5half+Sinf^2*li4half+6*li6half+3/2*s6;
Fill Stab6(1,1,0,0,0,-1) =-1/2*z2*z3*Sinf-7/40*z2^2*Sinf^2-167/
         280*z2^3+7/8*z3^2+93/32*z5*ln2+29/32*z5*Sinf-3/2*s6;
Fill Stab6(1,1,0,0,0,1) =z2*z3*Sinf+1/5*z2^2*Sinf^2+37/70*z2^3
         -z3^2-2*z5*Sinf;
Fill Stab6(1,1,0,0,1,-1) =5/8*z2*z3*ln2+1/6*z2*ln2^3*Sinf+1/12*
         z2*ln2^4+17/20*z2^2*ln2*Sinf+1/16*z2^2*Sinf^2-1271/1680*z2^3-
         7/8*z3*ln2*Sinf^2-7/8*z3*ln2^2*Sinf-7/24*z3*ln2^3-7/32*z3^2-
         93/64*z5*ln2-125/64*z5*Sinf+2*ln2*li5half-1/60*ln2^5*Sinf-1/
         90*ln2^6+2*Sinf*li5half+4*li6half+1/4*s6;
Fill Stab6(1,1,0,0,1,1) =1/4*z2^2*Sinf^2+53/84*z2^3-z3^2-1/2*
         z5*Sinf;
Fill Stab6(1,1,0,1,-1,-1) =7/8*z2*z3*ln2+7/8*z2*z3*Sinf+5/8*z2*
         ln2^2*Sinf^2-1/3*z2*ln2^3*Sinf-3/16*z2*ln2^4+2*z2*li4half-53/
         40*z2^2*ln2*Sinf+21/20*z2^2*ln2^2+1/80*z2^2*Sinf^2+59/112*z2^3
         +7/8*z3*ln2^2*Sinf+7/12*z3*ln2^3+11/64*z3^2+81/64*z5*Sinf+3/
         2*ln2^2*li4half+1/48*ln2^4*Sinf^2+1/30*ln2^5*Sinf+1/18*ln2^6-
         4*Sinf*li5half+1/2*Sinf^2*li4half-5*li6half-5/2*s6;
Fill Stab6(1,1,0,1,-1,1) =7/16*z2*z3*ln2-7/8*z2*z3*Sinf-1/8*z2*
         ln2^2*Sinf^2-3/4*z2*ln2^3*Sinf-5/12*z2*ln2^4+1/2*z2*li4half-
         51/40*z2^2*ln2*Sinf+13/20*z2^2*ln2^2-z2^2*Sinf^2-51/35*z2^3+
         21/16*z3*ln2*Sinf^2+35/16*z3*ln2^2*Sinf+49/48*z3*ln2^3+73/64*
         z3^2+93/64*z5*ln2+87/32*z5*Sinf+3*ln2*Sinf*li4half+4*ln2*
         li5half+3*ln2^2*li4half+1/12*ln2^4*Sinf^2+1/8*ln2^5*Sinf+67/
         720*ln2^6+2*Sinf^2*li4half+li6half-11/4*s6;
Fill Stab6(1,1,0,1,0,-1) =7/4*z2*z3*ln2-z2*z3*Sinf-1/2*z2*ln2^2*
         Sinf^2-2/3*z2*ln2^3*Sinf-1/6*z2*ln2^4+2*z2*li4half-1/2*z2^2*
         ln2^2-17/16*z2^2*Sinf^2-4393/1680*z2^3+7/4*z3*ln2*Sinf^2+7/4*
         z3*ln2^2*Sinf+7/12*z3*ln2^3+23/32*z3^2+279/64*z5*ln2-73/64*z5
         *Sinf+4*ln2*Sinf*li4half+4*ln2*li5half+2*ln2^2*li4half+1/12*
         ln2^4*Sinf^2+2/15*ln2^5*Sinf+1/18*ln2^6+4*Sinf*li5half+2*
         Sinf^2*li4half+4*li6half-9/4*s6;
Fill Stab6(1,1,0,1,0,1) =2*z2*z3*Sinf+7/20*z2^2*Sinf^2+443/420*
         z2^3-z3^2-11/2*z5*Sinf;
Fill Stab6(1,1,0,1,1,-1) =7/16*z2*z3*ln2-3/4*z2*ln2^2*Sinf^2-1/4
         *z2*ln2^3*Sinf-1/48*z2*ln2^4+3/2*z2*li4half+12/5*z2^2*ln2*Sinf
         -23/20*z2^2*ln2^2-3/5*z2^2*Sinf^2-101/35*z2^3+7/16*z3*ln2*
         Sinf^2+7/16*z3*ln2^2*Sinf+7/48*z3*ln2^3-6*z5*Sinf+3*ln2*Sinf*
         li4half+6*ln2*li5half+3/2*ln2^2*li4half+1/16*ln2^4*Sinf^2+3/
         40*ln2^5*Sinf+19/720*ln2^6+6*Sinf*li5half+3/2*Sinf^2*li4half+
         10*li6half;
Fill Stab6(1,1,0,1,1,1) =3/5*z2^2*Sinf^2+101/35*z2^3-6*z5*Sinf;
Fill Stab6(1,1,1,-1,-1,-1) =-7/6*z2*z3*ln2-1/8*z2*z3*Sinf-1/12
         *z2*ln2*Sinf^3+1/8*z2*ln2^2*Sinf^2-5/48*z2*ln2^4-3/2*z2*li4half
         +19/20*z2^2*ln2*Sinf+29/40*z2^2*ln2^2+3/5*z2^2*Sinf^2+61/35*
         z2^3-z3*ln2*Sinf^2-z3*ln2^2*Sinf-7/18*z3*ln2^3-1/24*z3*Sinf^3
         -1/12*z3^2-4*z5*ln2-4*z5*Sinf-1/36*ln2^3*Sinf^3-1/8*ln2^4*
         Sinf^2-1/12*ln2^5*Sinf-1/48*ln2^6+4*Sinf*li5half-3/2*Sinf^2*
         li4half-5*li6half;
Fill Stab6(1,1,1,-1,-1,1) =-1/6*z2*z3*ln2+7/8*z2*z3*Sinf-1/12*
         z2*ln2*Sinf^3+1/8*z2*ln2^2*Sinf^2-5/48*z2*ln2^4-3/2*z2*li4half
         -1/4*z2^2*ln2*Sinf+1/8*z2^2*ln2^2-1/18*z3*ln2^3+7/24*z3*
         Sinf^3+7/12*z3^2-1/36*ln2^3*Sinf^3-1/8*ln2^4*Sinf^2-1/12*
         ln2^5*Sinf-1/48*ln2^6+4*Sinf*li5half-3/2*Sinf^2*li4half-5*
         li6half;
Fill Stab6(1,1,1,-1,0,-1) =-1/3*z2*z3*ln2-1/16*z2*z3*Sinf-1/6*
         z2*ln2*Sinf^3+1/8*z2*ln2^2*Sinf^2+1/12*z2*ln2^3*Sinf-1/2*z2*
         li4half-7/20*z2^2*ln2*Sinf-1/20*z2^2*ln2^2+11/40*z2^2*Sinf^2+
         11/40*z2^3+13/48*z3*Sinf^3+19/24*z3^2-1/32*z5*Sinf-1/16*ln2^4
         *Sinf^2-1/40*ln2^5*Sinf-1/240*ln2^6+3*Sinf*li5half-3/2*Sinf^2
         *li4half-3*li6half+1/2*s6;
Fill Stab6(1,1,1,-1,0,1) =-55/48*z2*z3*ln2-1/16*z2*z3*Sinf+1/
         12*z2*ln2*Sinf^3+3/8*z2*ln2^2*Sinf^2+1/6*z2*ln2^3*Sinf-1/24*z2*
         ln2^4-3/2*z2*li4half+61/40*z2^2*ln2*Sinf+91/80*z2^2*ln2^2+7/
         16*z2^2*Sinf^2+661/560*z2^3-21/16*z3*ln2*Sinf^2-21/16*z3*ln2^2*
         Sinf-7/16*z3*ln2^3-1/6*z3*Sinf^3-179/384*z3^2-155/32*z5*ln2
         -39/8*z5*Sinf+ln2*Sinf*li4half+ln2*li5half+1/2*ln2^2*li4half
         -1/24*ln2^4*Sinf^2+1/120*ln2^5*Sinf+7/720*ln2^6+4*Sinf*
         li5half-Sinf^2*li4half-2*li6half+1/2*s6;
Fill Stab6(1,1,1,-1,1,-1) =-1/3*z2*z3*ln2-7/16*z2*z3*Sinf+1/12
         *z2*ln2*Sinf^3+1/4*z2*ln2^2*Sinf^2+1/4*z2*ln2^3*Sinf+1/16*z2*
         ln2^4+3/5*z2^2*ln2*Sinf+5/8*z2^2*ln2^2-1/40*z2^2*Sinf^2+7/40*
         z2^3-1/2*z3*ln2^2*Sinf-7/18*z3*ln2^3+1/48*z3*Sinf^3+2/3*z3^2
         +1/32*z5*Sinf-1/36*ln2^3*Sinf^3-1/16*ln2^4*Sinf^2-7/120*ln2^5
         *Sinf-1/60*ln2^6+Sinf*li5half-2*li6half-1/2*s6;
Fill Stab6(1,1,1,-1,1,1) =1/6*z2*z3*ln2+1/16*z2*z3*Sinf+1/12*z2*
         ln2*Sinf^3+1/4*z2*ln2^2*Sinf^2+1/4*z2*ln2^3*Sinf+1/16*z2*ln2^4
         +7/10*z2^2*ln2*Sinf+27/40*z2^2*ln2^2+1/40*z2^2*Sinf^2+111/280
         *z2^3-1/2*z3*ln2*Sinf^2-z3*ln2^2*Sinf-5/9*z3*ln2^3-7/48*z3*
         Sinf^3-1/6*z3^2-2*z5*ln2-63/32*z5*Sinf-1/36*ln2^3*Sinf^3-1/
         16*ln2^4*Sinf^2-7/120*ln2^5*Sinf-1/60*ln2^6+Sinf*li5half-2*
         li6half-1/2*s6;
Fill Stab6(1,1,1,0,-1,-1) =1/16*z2*z3*ln2-3/4*z2*z3*Sinf+1/4*z2*
         ln2*Sinf^3-1/8*z2*ln2^2*Sinf^2+1/12*z2*ln2^3*Sinf+5/48*z2*ln2^4
         +31/20*z2^2*ln2*Sinf-1/16*z2^2*Sinf^2-1/16*z2^3-7/16*z3*ln2^2
         *Sinf-7/24*z3*ln2^3-5/48*z3*Sinf^3+67/384*z3^2-27/32*z5*Sinf
         -1/2*ln2^2*li4half+1/48*ln2^4*Sinf^2-1/120*ln2^5*Sinf-7/360*
         ln2^6+Sinf*li5half+1/2*Sinf^2*li4half+li6half;
Fill Stab6(1,1,1,0,-1,1) =7/16*z2*z3*ln2+1/8*z2*z3*Sinf+1/6*z2*
         ln2^3*Sinf+7/48*z2*ln2^4+1/2*z2*li4half-1/8*z2^2*ln2^2-3/80*
         z2^2*Sinf^2+15/112*z2^3-7/16*z3*ln2^2*Sinf-7/24*z3*ln2^3-5/48
         *z3*Sinf^3-29/384*z3^2+31/32*z5*ln2+1/8*z5*Sinf-ln2*Sinf*
         li4half-2*ln2*li5half-ln2^2*li4half-1/30*ln2^5*Sinf-1/36*
         ln2^6-Sinf*li5half-2*li6half-1/2*s6;
Fill Stab6(1,1,1,0,0,-1) =-7/8*z2*z3*ln2+1/8*z2*z3*Sinf+1/4*z2
         *ln2^2*Sinf^2+1/3*z2*ln2^3*Sinf+1/12*z2*ln2^4-z2*li4half+1/4*
         z2^2*ln2^2+3/8*z2^2*Sinf^2+257/280*z2^3-7/8*z3*ln2*Sinf^2-7/8
         *z3*ln2^2*Sinf-7/24*z3*ln2^3-1/8*z3*Sinf^3-3/8*z3^2-31/32*z5*
         ln2+33/32*z5*Sinf-2*ln2*Sinf*li4half-2*ln2*li5half-ln2^2*
         li4half-1/24*ln2^4*Sinf^2-1/15*ln2^5*Sinf-1/36*ln2^6-2*Sinf*
         li5half-Sinf^2*li4half-2*li6half+1/2*s6;
Fill Stab6(1,1,1,0,0,1) =-1/2*z2*z3*Sinf-1/20*z2^2*Sinf^2-31/
         140*z2^3+1/6*z3*Sinf^3+5/6*z3^2+2*z5*Sinf;
Fill Stab6(1,1,1,0,1,-1) =-11/8*z2*z3*ln2+1/8*z2*z3*Sinf-1/4*
         z2*ln2*Sinf^3+3/8*z2*ln2^2*Sinf^2+5/12*z2*ln2^3*Sinf+1/12*z2*
         ln2^4-3/2*z2*li4half-31/20*z2^2*ln2*Sinf+3/8*z2^2*ln2^2+3/5*
         z2^2*Sinf^2+61/35*z2^3-7/8*z3*ln2*Sinf^2-7/8*z3*ln2^2*Sinf-7/
         24*z3*ln2^3+1/24*z3*Sinf^3+1/12*z3^2+4*z5*Sinf-3*ln2*Sinf*
         li4half-4*ln2*li5half-3/2*ln2^2*li4half-1/16*ln2^4*Sinf^2-11/
         120*ln2^5*Sinf-13/360*ln2^6-4*Sinf*li5half-3/2*Sinf^2*li4half
         -5*li6half;
Fill Stab6(1,1,1,0,1,1) =z2*z3*Sinf-3/5*z2^2*Sinf^2-61/35*z2^3
         +1/3*z3*Sinf^3+2/3*z3^2+4*z5*Sinf;
Fill Stab6(1,1,1,1,-1,-1) =1/6*z2*z3*ln2-13/48*z2*z3*Sinf+1/12*
         z2*ln2*Sinf^3+1/8*z2*ln2^2*Sinf^2+1/6*z2*ln2^3*Sinf+1/12*z2*
         ln2^4+1/48*z2*Sinf^4+1/2*z2*li4half+1/4*z2^2*ln2*Sinf+9/80*
         z2^2*ln2^2+1/8*z2^2*Sinf^2+9/80*z2^3+1/6*z3*ln2^2*Sinf+1/9*z3
         *ln2^3-7/48*z3*Sinf^3-7/24*z3^2+1/48*ln2^2*Sinf^4+1/18*ln2^3*
         Sinf^3+1/12*ln2^4*Sinf^2+1/24*ln2^5*Sinf+1/120*ln2^6-Sinf*
         li5half+1/2*Sinf^2*li4half+li6half;
Fill Stab6(1,1,1,1,-1,1) =1/3*z2*z3*ln2-5/48*z2*z3*Sinf-1/12*z2*
         ln2*Sinf^3-1/8*z2*ln2^2*Sinf^2+1/24*z2*ln2^4-1/48*z2*Sinf^4+1/
         2*z2*li4half-13/20*z2^2*ln2*Sinf-27/80*z2^2*ln2^2-13/40*z2^2*
         Sinf^2-303/560*z2^3+1/2*z3*ln2*Sinf^2+2/3*z3*ln2^2*Sinf+5/18*
         z3*ln2^3+1/48*z3*Sinf^3+1/24*z3^2+z5*ln2+z5*Sinf+1/48*ln2^2
         *Sinf^4+1/18*ln2^3*Sinf^3+1/12*ln2^4*Sinf^2+1/24*ln2^5*Sinf+1/
         120*ln2^6-Sinf*li5half+1/2*Sinf^2*li4half+li6half;
Fill Stab6(1,1,1,1,0,-1) =7/16*z2*z3*ln2-11/48*z2*z3*Sinf-1/8*z2
         *ln2^2*Sinf^2-1/6*z2*ln2^3*Sinf-1/24*z2*ln2^4-1/48*z2*Sinf^4+
         1/2*z2*li4half-1/8*z2^2*ln2^2-13/40*z2^2*Sinf^2-303/560*z2^3+
         7/16*z3*ln2*Sinf^2+7/16*z3*ln2^2*Sinf+7/48*z3*ln2^3-1/48*z3*
         Sinf^3-1/24*z3^2-z5*Sinf+ln2*Sinf*li4half+ln2*li5half+1/2*
         ln2^2*li4half+1/48*ln2^4*Sinf^2+1/30*ln2^5*Sinf+1/72*ln2^6+
         Sinf*li5half+1/2*Sinf^2*li4half+li6half;
Fill Stab6(1,1,1,1,0,1) =-1/6*z2*z3*Sinf+1/24*z2*Sinf^4+9/20*
         z2^2*Sinf^2+183/280*z2^3-1/6*z3*Sinf^3-1/3*z3^2-z5*Sinf;
Fill Stab6(1,1,1,1,1,-1) =-1/6*z2*z3*ln2-1/12*z2*ln2*Sinf^3-1/
         8*z2*ln2^2*Sinf^2-1/12*z2*ln2^3*Sinf-1/48*z2*ln2^4-9/40*z2^2*
         ln2*Sinf-9/80*z2^2*ln2^2-1/6*z3*ln2*Sinf^2-1/6*z3*ln2^2*Sinf-
         1/18*z3*ln2^3-1/5*z5*ln2-1/120*ln2*Sinf^5-1/48*ln2^2*Sinf^4-1/
         36*ln2^3*Sinf^3-1/48*ln2^4*Sinf^2-1/120*ln2^5*Sinf-1/720*ln2^6;
Fill Stab6(1,1,1,1,1,1) =1/6*z2*z3*Sinf+1/48*z2*Sinf^4+9/80*z2^2
         *Sinf^2+61/560*z2^3+1/18*z3*Sinf^3+1/18*z3^2+1/5*z5*Sinf+1/
         720*Sinf^6;
#endprocedure
*
*--#] table6 : 
*--#[ tables :
*
#procedure tables(size)
*
*   Tables of harmonic series at infinity.
*   Note that the definition of these series is slightly different from
*   what are called Euler/Zagier sums.
*   Notation for the tables:
*   A zero index means that one should be added to the absolute value
*   of the next index. The argument is inf (infinity).
*   Example: S(0,-1,0,0,2,1) = S(R(-2,3,1),inf)
*   The various weights are in separate files.
*   This makes that FORM will not even touch the table7.prc file if
*   size < 7. That saves much time.
*   File by J. Vermaseren, 5-jun-1998
*
#do itabs = 1,`size'
#call table`itabs'
#enddo
#endprocedure
*
*--#] tables : 
*--#[ theta :
*
#procedure theta(i)
*
*   Routine deals with combinations of theta, delta, deltap and
*   sum functions. These are defined for each j`i'. The parameter gives the
*   i for which we have to do this. If we have to do them all we have to
*   sum over i. i=0 is not summed over.
*   An parameter N signifies N (which is usually identical to j0,
*   but we can always assume that N >= 0).
*
*   Note: theta(x) = 1, x >= 0, = 0, x < 0
*         delta(x) = 1, x = 0,  = 0, x != 0
*         deltap(x)= 1, x != 0, = 0, x = 0
*
*   NOTE! We make at one point the assumption that thetap(x) = theta(x+1)
*   The statement that assumes this has been marked with ***** in front.
*
*   At all points we assume that N >= 0 and j`i' >= 0!!!!
*   The statements
*   id den(ep) = acc(1/ep) are for a special application.
*   In normal use they should be harmless.
*
*   Routine by J.Vermaseren, 17-jan-1998
*
#if `i' == N
  repeat id theta(x1?,x2?,?a) = theta(x1+x2,?a);
  repeat id delta(x1?,x2?,?a) = delta(x1+x2,?a);
  repeat id deltap(x1?,x2?,?a) = deltap(x1+x2,?a);
  repeat id theta(x?)*theta(x?) = theta(x);
  repeat id delta(x?)*delta(x?) = delta(x);
  repeat id deltap(x?)*deltap(x?) = deltap(x);
  id  delta(x?)*deltap(x?) = 0;
  SplitArg,(N),theta,delta,deltap;
  id  theta(x?,N/2) = theta(2*x,N);
  id  theta(x?,-N/2) = theta(2*x,-N);
  id  theta(N/2) = theta(0,N);
  id  theta(-N/2) = delta(N);
  id  delta(N/2) = delta(N);
  id  delta(-N/2) = delta(N);
  id  delta(x?,N/2) = delta(2*x,N);
  id  delta(x?,-N/2) = delta(2*x,-N);
  id  deltap(N/2) = deltap(N);
  id  deltap(-N/2) = deltap(N);
  id  deltap(x?,N/2) = deltap(2*x,N);
  id  deltap(x?,-N/2) = deltap(2*x,-N);
  id  theta(x?neg_,-N) = 0;
  id  delta(x?neg_,-N) = 0;
  id  delta(x?pos_,N) = 0;
  id  theta(x?neg_,-2*N) = 0;
  id  delta(x?neg_,-2*N) = 0;
  id  delta(x?pos_,2*N) = 0;
  id  theta(0,-N) = delta(0,N);
  id  theta(N) = theta(0,N);
  id  theta(2*N) = theta(0,N);
  id  theta(-N) = delta(0,N);
  id  theta(-2*N) = delta(0,N);
  id  delta(N) = delta(0,N);
  id  deltap(N) = theta(-1,N);
  id  delta(-N) = delta(0,N);
  id  deltap(-N) = theta(-1,N);
  id  delta(2*N) = delta(0,N);
  id  deltap(2*N) = theta(-1,N);
  id  delta(-2*N) = delta(0,N);
  id  deltap(-2*N) = theta(-1,N);
  id  delta(x?,-N) = delta(-x,N);
  id  deltap(x?,-N) = deltap(-x,N);
  id  delta(x?,-2*N) = delta(-x/2,N)*Even(x);
  id  deltap(x?,-2*N) = deltap(-x/2,N);
  id  delta(x?,2*N) = delta(x/2,N)*Even(x);
  id  deltap(x?,2*N) = deltap(x/2,N);
  id  deltap(x?,N) = delta_(x)*theta(-1,N)
      +acc1(theta_(x)-delta_(x))*theta(0,N)
      +acc1(1-theta_(x))*(theta(x-1,N)+theta(-x-1,-N));
  id  theta(x?neg_,-N) = 0;
  id  acc1(x?) = x;
  id,once,delta(x?,N) = theta_(-x)*su(x)*replace_(N,-x);
  repeat id,once,theta(x1?,N)*theta(x2?,N) =
          +theta(x1,N)*theta_(x2-x1)
          +theta(x2,N)*(theta_(x1-x2)-delta_(x1-x2))
          ;
  repeat id,once,theta(x1?,-N)*theta(x2?,-N) =
          +theta(x1,-N)*theta_(x2-x1)
          +theta(x2,-N)*(theta_(x1-x2)-delta_(x1-x2))
          ;
  id  theta(x?pos0_,-N) = sum_(jjj,0,x,delta(-jjj,N));
  id,once,delta(x?,N) = theta_(-x)*su(x)*replace_(N,-x);
  id  su(x?) = delta(x+N);
      #do ii = 1,`MAXWEIGHT'
      if ( match(sum`ii'(j`ii',x1?,x2?)) );
          id  sum`ii'(j`ii',x1?,x2?) = sum`ii'(j`ii',x1,x2,x2-x1);
          if ( match(sum`ii'(j`ii',x1?,x2?,x3?pos0_)) );
              id  theta`ii'(x1?,x2?) = theta_(x1+x2);
              id  den`ii'(x1?,x2?) = den(x1+x2);
              id  fac`ii'(x1?,x2?) = fac(x1+x2);
              id  invfac`ii'(x1?,x2?) = invfac(x1+x2);
              id  S`ii'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
              id  bino`ii'(x1?,x2?,x3?) = fac(x1)*invfac(x2+x3)*invfac(x1-x2-x3);
              id  sign`ii'(x?) = sign(x);
              repeat id sum`ii'(j`ii',x1?,x2?,x3?pos0_) =
                   sum`ii'(j`ii',x1,x2-1,x3-1)+replace_(j`ii',x2);
              id  sum`ii'(j`ii',x1?,x2?,x3?neg_) = 0;
          else;
              id  sum`ii'(j`ii',x1?,x2?,x3?neg_) = 0;
              id  sum`ii'(j`ii',x1?,x2?,x3?) = sum`ii'(j`ii',x1,x2);
          endif;
      else;
          id  theta`ii'(x1?,x2?) = theta_(x1+x2);
          id  delta`ii'(x1?,x2?) = delta_(x1+x2);
          id  deltap`ii'(x1?,x2?) = deltap_(x1+x2);
          id  den`ii'(x1?,x2?) = den(x1+x2);
          id  fac`ii'(x1?,x2?) = fac(x1+x2);
          id  invfac`ii'(x1?,x2?) = invfac(x1+x2);
          id  S`ii'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
          id  bino`ii'(x1?,x2?,x3?) = fac_(x1)*invfac_(x2+x3)*invfac_(x1-x2-x3);
          id  sign`ii'(x?) = sign_(x);
      endif;
      #enddo
      id  den(ep) = acc(1/ep);
  id  delta(x1?,x2?) = delta(x1+x2);
  id  deltap(x1?,x2?) = deltap(x1+x2);
  id  theta(x1?,x2?) = theta(x1+x2);
  id  delta(x?) = delta_(x);
  id  delta_(x?) = delta(x);
  id  deltap(x?) = deltap_(x);
  id  deltap_(x?) = deltap(x);
  id  theta(x?) = theta_(x);
  id  theta_(x?) = theta(x);
#else
  repeat id f?{theta,theta0,...,theta`i',delta,delta0,...,delta`i',deltap,deltap0,...,deltap`i'}(x1?,x2?,?a) = f(x1+x2,?a);
  id  f?{theta0,...,theta`i'}(x?) = theta(x);
  id  f?{delta0,...,delta`i'}(x?) = delta(x);
  id  f?{deltap0,...,deltap`i'}(x?) = deltap(x);
  id  theta_(x?) = theta(x);
  id  delta_(x?) = delta(x);
  id  deltap_(x?) = deltap(x);
  repeat id theta(x?)*theta(x?) = theta(x);
  repeat id delta(x?)*delta(x?) = delta(x);
  repeat id deltap(x?)*deltap(x?) = deltap(x);
  SplitArg,(j`i'),theta,delta,deltap;
  id  delta(x?,j`i') = delta`i'(x,j`i');
  id  deltap(x?,j`i') = deltap`i'(x,j`i');
  id  theta(x?,j`i') = theta`i'(x,j`i');
  id  delta(x?,2*j`i') = delta`i'(x/2,j`i')*Even(x);
  id  deltap(x?,2*j`i') = deltap`i'(x,2*j`i');
  id  theta(x?,2*j`i') = theta`i'(x/2,j`i');
  id  delta(x?,-j`i') = delta`i'(-x,j`i');
  id  deltap(x?,-j`i') = deltap`i'(-x,j`i');
  id  theta(x?,-j`i') = theta`i'(x,-j`i');
  id  delta(x?,-2*j`i') = delta`i'(-x/2,j`i')*Even(x);
  id  deltap(x?,-2*j`i') = deltap`i'(-x,2*j`i');
  id  theta(x?,-2*j`i') = theta`i'(x/2,-j`i');
  id  delta(j`i') = delta`i'(0,j`i');
  id  deltap(j`i') = deltap`i'(0,j`i');
  id  theta(j`i') = theta`i'(0,j`i');
  id  delta(-j`i') = delta`i'(0,j`i');
  id  deltap(-j`i') = deltap`i'(0,j`i');
  id  theta(-j`i') = delta`i'(0,j`i');
  id  delta(2*j`i') = delta`i'(0,j`i');
  id  deltap(2*j`i') = deltap`i'(0,j`i');
  id  theta(2*j`i') = theta`i'(0,j`i');
  id  delta(-2*j`i') = delta`i'(0,j`i');
  id  deltap(-2*j`i') = deltap`i'(0,j`i');
  id  theta(-2*j`i') = delta`i'(0,j`i');
  id  delta`i'(x?pos_,j`i') = 0;
  id  delta`i'(x?neg_,-j`i') = 0;
  id  deltap`i'(x?pos_,j`i') = 1;
  id  deltap`i'(x?pos_,2*j`i') = 1;
  id  deltap`i'(x?neg_,-j`i') = 1;
  id  theta`i'(x?pos0_,j`i') = 1;
  id  theta`i'(x?neg_,-j`i') = 0;
  #if `i' == 0
*
*   No sum taking place.
*
  #else
    id  sum`i'(j`i',x1?,x2?)*delta`i'(x?,j`i') =
            replace_(j`i',-x)*theta(x2+x)*theta(-x-x1)*theta(x2-x1);
*
*   Remaining delta`i' functions do not depend on j`i' any longer:
*
    if ( count(sum`i',1) == 0 );
        id  theta`i'(x1?,x2?) = theta(x1+x2);
        id  delta`i'(x1?,x2?) = delta(x1+x2);
        id  deltap`i'(x1?,x2?) = deltap(x1+x2);
    else;
*****
    repeat id sum`i'(j`i',x1?,x2?)*deltap`i'(x?,j`i') =
            +sum`i'(j`i',x1,x2)*(theta`i'(x-1,j`i')+theta`i'(-x-1,-j`i'));
    repeat id sum`i'(j`i',x1?,x2?)*deltap`i'(x?,2*j`i') =
            +sum`i'(j`i',x1,x2)*(theta`i'(x/2-1/2,j`i')+theta`i'(-x/2-1/2,-j`i'));
    repeat id theta`i'(?a)*theta`i'(?a) = theta`i'(?a);
    endif;
  #endif
*
*   Now we have eliminated the delta functions.
*   Next are the theta functions. We first try to combine them.
*
  repeat id theta`i'(x1?,j`i')*theta`i'(x2?,j`i') =
          +theta`i'(x1,j`i')*theta(x2-x1)
          +theta`i'(x2,j`i')*(theta(x1-x2)-delta(x1-x2))
          ;
  repeat id theta`i'(x1?,-j`i')*theta`i'(x2?,-j`i') =
          +theta`i'(x1,-j`i')*theta(x2-x1)
          +theta`i'(x2,-j`i')*(theta(x1-x2)-delta(x1-x2))
          ;
  repeat id delta`i'(x?,j`i')*delta`i'(x?,j`i') = delta`i'(x,j`i');
  #if `i' == 0
*
  #else
  if ( count(delta`i',1) > 0 );
      id  sum`i'(j`i',x1?,x2?)*delta`i'(x?,j`i') =
              replace_(j`i',-x)*theta(x2+x)*theta(-x-x1);
  endif;
  if ( count(sum`i',1) == 0 );
      id  theta`i'(x1?,x2?) = theta(x1+x2);
      id  delta`i'(x1?,x2?) = delta(x1+x2);
      id  deltap`i'(x1?,x2?) = deltap(x1+x2);
  endif;
  id sum`i'(j`i',x1?,x2?)*theta`i'(x?,j`i') =
          +sum`i'(j`i',x1,x2)*theta(x1+x)
          +sum`i'(j`i',-x,x2)*theta(x2+x)*(theta(-x1-x)-delta(x+x1));
  id sum`i'(j`i',x1?,x2?)*theta`i'(x?,-j`i') =
          +sum`i'(j`i',x1,x2)*theta(x-x2)
          +sum`i'(j`i',x1,x)*theta(x-x1)*(theta(x2-x)-delta(x-x2));
  #endif
      if ( match(sum`i'(j`i',x1?,x2?)) );
          id  sum`i'(j`i',x1?,x2?) = sum`i'(j`i',x1,x2,x2-x1);
          if ( match(sum`i'(j`i',x1?,x2?,x3?pos0_)) );
              id  delta`i'(x1?,x2?) = delta_(x1+x2);
              id  deltap`i'(x1?,x2?) = deltap_(x1+x2);
              id  theta`i'(x1?,x2?) = theta_(x1+x2);
              id  den`i'(x1?,x2?) = den(x1+x2);
              id  fac`i'(x1?,x2?) = fac(x1+x2);
              id  invfac`i'(x1?,x2?) = invfac(x1+x2);
              id  S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
              id  bino`i'(x1?,x2?,x3?) = fac(x1)*invfac(x2+x3)*invfac(x1-x2-x3);
              id  sign`i'(x?) = sign(x);
              repeat id sum`i'(j`i',x1?,x2?,x3?pos0_) =
                   sum`i'(j`i',x1,x2-1,x3-1)+replace_(j`i',x2);
              id  sum`i'(j`i',x1?,x2?,x3?neg_) = 0;
              #do ii = `i'+1,`MAXWEIGHT'
              if ( match(sum`ii'(j`ii',x1?,x2?)) );
                  id  sum`ii'(j`ii',x1?,x2?) = sum`ii'(j`ii',x1,x2,x2-x1);
                  if ( match(sum`ii'(j`ii',x1?,x2?,x3?int_)) );
                      id  theta`ii'(x1?,x2?) = theta_(x1+x2);
                      id  den`ii'(x1?,x2?) = den(x1+x2);
                      id  fac`ii'(x1?,x2?) = fac(x1+x2);
                      id  invfac`ii'(x1?,x2?) = invfac(x1+x2);
                      id  S`ii'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
                      id  bino`ii'(x1?,x2?,x3?) = fac(x1)*invfac(x2+x3)*invfac(x1-x2-x3);
                      id  sign`ii'(x?) = sign(x);
                      repeat id sum`ii'(j`ii',x1?,x2?,x3?pos0_) =
                           sum`ii'(j`ii',x1,x2-1,x3-1)+replace_(j`ii',x2);
                      id  sum`ii'(j`ii',x1?,x2?,x3?neg_) = 0;
                  else;
                      id  sum`ii'(j`ii',x1?,x2?,x3?) = sum`ii'(j`ii',x1,x2);
              #enddo
              #do ii = `i'+1,`MAXWEIGHT'
                  endif;
              endif;
              #enddo
          else;
              id  sum`i'(j`i',x1?,x2?,x3?neg_) = 0;
              id  sum`i'(j`i',x1?,x2?,x3?) = sum`i'(j`i',x1,x2);
          endif;
          id  den(ep) = acc(1/ep);
      else;
          id  theta`i'(x1?,x2?) = theta_(x1+x2);
          id  delta`i'(x1?,x2?) = delta_(x1+x2);
          id  deltap`i'(x1?,x2?) = deltap_(x1+x2);
          id  den`i'(x1?,x2?) = den(x1+x2);
          id  fac`i'(x1?,x2?) = fac(x1+x2);
          id  invfac`i'(x1?,x2?) = invfac(x1+x2);
          id  S`i'(R(?a),x1?,x2?) = S(R(?a),x1+x2);
          id  bino`i'(x1?,x2?,x3?) = fac_(x1)*invfac_(x2+x3)*invfac_(x1-x2-x3);
          id  sign`i'(x?) = sign_(x);
      endif;
      id  den(ep) = acc(1/ep);
  
  id  theta(x1?,x2?) = theta(x1+x2);
  id  delta(x1?,x2?) = delta(x1+x2);
  id  deltap(x1?,x2?) = deltap(x1+x2);
  id  delta(x?) = delta_(x);
  id  delta_(x?) = delta(x);
  id  deltap(x?) = deltap_(x);
  id  deltap_(x?) = deltap(x);
  id  theta(x?) = theta_(x);
  id  theta_(x?) = theta(x);
#endif
*
#endprocedure
*
*--#] theta : 
*--#[ StoZ :
*
#procedure StoZ(S,Z)
*
repeat;
  id,once,`S'(R(?a,n1?),N?) = SSZZ(R(n1),R(?a),N);
  repeat;
	id,SSZZ(R(n1?,?a),R(?b,n2?),N?) =
			SSZZ(R(n2,n1,?a),R(?b),N)
				+SSZZ(R(n1*sig_(n2)+n2*sig_(n1),?a),R(?b),N);
  endrepeat;
  id	SSZZ(R(?a),R,N?) = `Z'(R(?a),N);
endrepeat;
*
#endprocedure
*
*--#] StoZ : 
*--#[ ZtoS :
*
#procedure ZtoS(Z,S)
*
repeat;
  id,once,`Z'(R(?a,n1?),N?) = SSZZ(R(n1),R(?a),N);
  repeat;
	id,SSZZ(R(n1?,?a),R(?b,n2?),N?) =
			SSZZ(R(n2,n1,?a),R(?b),N)
				-SSZZ(R(n1*sig_(n2)+n2*sig_(n1),?a),R(?b),N);
  endrepeat;
  id	SSZZ(R(?a),R,N?) = `S'(R(?a),N);
endrepeat;
*
#endprocedure
*
*--#] ZtoS : 
*--#] Procedures :
*--#[ Programs :
*--#[ Powsum :
*
*	This program is used to derive the powsum tables in the nndecl part.
*	Here it is deactivated with the #ifdef.
*	If you need to extend the tables, please copy the code to a separate
*	file (for example sumprog.frm), give MAX its proper value and run it.
*	Finally convert the output into extra code for filling the tables in
*	the nndecl.h part of this file.
*
#ifdef `THISISSUMPROGFORPOWSUM'
#-
#define MAX "20"
#include summer.h
CF	F;
Format nospaces;
Off Statistics;
.global
*
*	We use the relation
*	sum(j,1,n,n*(n+1)*...*(n+k)) = n*(n+1)*...*(n+k+1)/(k+2)
*	The one with the sign we do via the doubling formula
*	Program by Jos Vermaseren, 4-sep-2003
*
#do i = 1,`MAX'
G	F`i'(n) = n^`i';
#enddo
Multiply num(0,n);
#do i = 0,`MAX'
id	num(x?,n)*n = num(x+1,n)-num(x,n)*x;
.sort
#enddo
id	num(i?,n?) = num(i+1,n)/(i+1);
repeat id num(i?pos_,n?) = num1(n)*num(i-1,n+1);
id	num(0,n?) = 1;
repeat id num1(x1?)*num1(x2?) = num1(x1*x2);
id	num1(x?) = x;
Print +f;
.store
#do i = 1,`MAX'
G	G`i' = (1+sign_(n))/2*(2*2^`i'*F(`i',n/2)-F(`i',n))
          +(1-sign_(n))/2*(2*2^`i'*F(`i',(n+1)/2)-F(`i',n+1)+(n+1)^`i'*sign_(n));
#enddo
#do i = 1,`MAX'
id	F(`i',nn?) = F`i'(nn);
#enddo
id	sign_(n)*sign_(n) = 1;
B	sign_;
Print +f;
.store
#do i = 1,`MAX'
G	FF`i'(n) = F`i'(n);
#enddo
#do i = 1,`MAX'
G	GG`i'(n) = G`i';
#enddo
Multiply replace_(n,n-1);
id	sign_(n-1) = -sign_(n);
B	sign_;
Print +f;
.end
#endif
*
*--#] Powsum : 
*--#] Programs : 
#endif
