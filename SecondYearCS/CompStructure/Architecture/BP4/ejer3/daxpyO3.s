
daxpyO3:     formato del fichero elf64-x86-64


Desensamblado de la sección .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Desensamblado de la sección .plt:

0000000000001020 <.plt>:
    1020:	ff 35 5a 2f 00 00    	pushq  0x2f5a(%rip)        # 3f80 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 5b 2f 00 00 	bnd jmpq *0x2f5b(%rip)        # 3f88 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop

Desensamblado de la sección .plt.got:

00000000000010c0 <__cxa_finalize@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 2d 2f 00 00 	bnd jmpq *0x2f2d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Desensamblado de la sección .plt.sec:

00000000000010d0 <omp_get_wtime@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 b5 2e 00 00 	bnd jmpq *0x2eb5(%rip)        # 3f90 <omp_get_wtime@OMP_2.0>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010e0 <__stack_chk_fail@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 ad 2e 00 00 	bnd jmpq *0x2ead(%rip)        # 3f98 <__stack_chk_fail@GLIBC_2.4>
    10eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010f0 <strtol@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 a5 2e 00 00 	bnd jmpq *0x2ea5(%rip)        # 3fa0 <strtol@GLIBC_2.2.5>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001100 <time@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 9d 2e 00 00 	bnd jmpq *0x2e9d(%rip)        # 3fa8 <time@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001110 <srand48@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 95 2e 00 00 	bnd jmpq *0x2e95(%rip)        # 3fb0 <srand48@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001120 <__printf_chk@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 8d 2e 00 00 	bnd jmpq *0x2e8d(%rip)        # 3fb8 <__printf_chk@GLIBC_2.3.4>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <exit@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 85 2e 00 00 	bnd jmpq *0x2e85(%rip)        # 3fc0 <exit@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <fwrite@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 7d 2e 00 00 	bnd jmpq *0x2e7d(%rip)        # 3fc8 <fwrite@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <drand48@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 75 2e 00 00 	bnd jmpq *0x2e75(%rip)        # 3fd0 <drand48@GLIBC_2.2.5>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Desensamblado de la sección .text:

0000000000001160 <main>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	55                   	push   %rbp
    1165:	48 89 e5             	mov    %rsp,%rbp
    1168:	41 57                	push   %r15
    116a:	41 56                	push   %r14
    116c:	41 55                	push   %r13
    116e:	41 54                	push   %r12
    1170:	53                   	push   %rbx
    1171:	48 83 ec 28          	sub    $0x28,%rsp
    1175:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    117c:	00 00 
    117e:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    1182:	31 c0                	xor    %eax,%eax
    1184:	83 ff 01             	cmp    $0x1,%edi
    1187:	0f 8e ec 02 00 00    	jle    1479 <main+0x319>
    118d:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    1191:	ba 0a 00 00 00       	mov    $0xa,%edx
    1196:	31 f6                	xor    %esi,%esi
    1198:	e8 53 ff ff ff       	callq  10f0 <strtol@plt>
    119d:	48 89 e6             	mov    %rsp,%rsi
    11a0:	89 45 b8             	mov    %eax,-0x48(%rbp)
    11a3:	49 89 c5             	mov    %rax,%r13
    11a6:	48 98                	cltq   
    11a8:	48 8d 04 c5 0f 00 00 	lea    0xf(,%rax,8),%rax
    11af:	00 
    11b0:	48 89 c1             	mov    %rax,%rcx
    11b3:	48 89 c2             	mov    %rax,%rdx
    11b6:	48 81 e1 00 f0 ff ff 	and    $0xfffffffffffff000,%rcx
    11bd:	48 83 e2 f0          	and    $0xfffffffffffffff0,%rdx
    11c1:	48 29 ce             	sub    %rcx,%rsi
    11c4:	48 89 f1             	mov    %rsi,%rcx
    11c7:	48 39 cc             	cmp    %rcx,%rsp
    11ca:	74 15                	je     11e1 <main+0x81>
    11cc:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    11d3:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    11da:	00 00 
    11dc:	48 39 cc             	cmp    %rcx,%rsp
    11df:	75 eb                	jne    11cc <main+0x6c>
    11e1:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    11e7:	48 29 d4             	sub    %rdx,%rsp
    11ea:	48 85 d2             	test   %rdx,%rdx
    11ed:	75 3d                	jne    122c <main+0xcc>
    11ef:	4c 8d 64 24 07       	lea    0x7(%rsp),%r12
    11f4:	48 89 c2             	mov    %rax,%rdx
    11f7:	48 89 e7             	mov    %rsp,%rdi
    11fa:	48 25 00 f0 ff ff    	and    $0xfffffffffffff000,%rax
    1200:	4c 89 e3             	mov    %r12,%rbx
    1203:	48 29 c7             	sub    %rax,%rdi
    1206:	49 83 e4 f8          	and    $0xfffffffffffffff8,%r12
    120a:	48 83 e2 f0          	and    $0xfffffffffffffff0,%rdx
    120e:	48 c1 eb 03          	shr    $0x3,%rbx
    1212:	48 89 f8             	mov    %rdi,%rax
    1215:	48 39 c4             	cmp    %rax,%rsp
    1218:	74 1a                	je     1234 <main+0xd4>
    121a:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1221:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    1228:	00 00 
    122a:	eb e9                	jmp    1215 <main+0xb5>
    122c:	48 83 4c 14 f8 00    	orq    $0x0,-0x8(%rsp,%rdx,1)
    1232:	eb bb                	jmp    11ef <main+0x8f>
    1234:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    123a:	48 29 d4             	sub    %rdx,%rsp
    123d:	48 85 d2             	test   %rdx,%rdx
    1240:	0f 85 21 02 00 00    	jne    1467 <main+0x307>
    1246:	31 ff                	xor    %edi,%edi
    1248:	4c 8d 74 24 07       	lea    0x7(%rsp),%r14
    124d:	e8 ae fe ff ff       	callq  1100 <time@plt>
    1252:	4d 89 f7             	mov    %r14,%r15
    1255:	49 83 e6 f8          	and    $0xfffffffffffffff8,%r14
    1259:	48 89 c7             	mov    %rax,%rdi
    125c:	49 c1 ef 03          	shr    $0x3,%r15
    1260:	e8 ab fe ff ff       	callq  1110 <srand48@plt>
    1265:	41 83 fd 07          	cmp    $0x7,%r13d
    1269:	0f 8f 97 01 00 00    	jg     1406 <main+0x2a6>
    126f:	45 85 ed             	test   %r13d,%r13d
    1272:	0f 8e db 01 00 00    	jle    1453 <main+0x2f3>
    1278:	41 8d 45 ff          	lea    -0x1(%r13),%eax
    127c:	83 f8 02             	cmp    $0x2,%eax
    127f:	0f 86 ed 01 00 00    	jbe    1472 <main+0x312>
    1285:	66 0f 28 05 b3 0d 00 	movapd 0xdb3(%rip),%xmm0        # 2040 <_IO_stdin_used+0x40>
    128c:	00 
    128d:	66 0f 6e 65 b8       	movd   -0x48(%rbp),%xmm4
    1292:	44 89 e8             	mov    %r13d,%eax
    1295:	83 e0 fc             	and    $0xfffffffc,%eax
    1298:	0f 11 04 dd 00 00 00 	movups %xmm0,0x0(,%rbx,8)
    129f:	00 
    12a0:	66 0f 28 05 a8 0d 00 	movapd 0xda8(%rip),%xmm0        # 2050 <_IO_stdin_used+0x50>
    12a7:	00 
    12a8:	0f 11 04 dd 10 00 00 	movups %xmm0,0x10(,%rbx,8)
    12af:	00 
    12b0:	66 0f 70 c4 00       	pshufd $0x0,%xmm4,%xmm0
    12b5:	66 0f fa 05 a3 0d 00 	psubd  0xda3(%rip),%xmm0        # 2060 <_IO_stdin_used+0x60>
    12bc:	00 
    12bd:	f3 0f e6 c8          	cvtdq2pd %xmm0,%xmm1
    12c1:	66 0f 70 c0 ee       	pshufd $0xee,%xmm0,%xmm0
    12c6:	42 0f 11 0c fd 00 00 	movups %xmm1,0x0(,%r15,8)
    12cd:	00 00 
    12cf:	f3 0f e6 c0          	cvtdq2pd %xmm0,%xmm0
    12d3:	42 0f 11 04 fd 10 00 	movups %xmm0,0x10(,%r15,8)
    12da:	00 00 
    12dc:	41 39 c5             	cmp    %eax,%r13d
    12df:	0f 84 52 01 00 00    	je     1437 <main+0x2d7>
    12e5:	66 0f ef c0          	pxor   %xmm0,%xmm0
    12e9:	48 63 c8             	movslq %eax,%rcx
    12ec:	44 89 ea             	mov    %r13d,%edx
    12ef:	f2 0f 2a c0          	cvtsi2sd %eax,%xmm0
    12f3:	29 c2                	sub    %eax,%edx
    12f5:	f2 41 0f 11 04 cc    	movsd  %xmm0,(%r12,%rcx,8)
    12fb:	66 0f ef c0          	pxor   %xmm0,%xmm0
    12ff:	f2 0f 2a c2          	cvtsi2sd %edx,%xmm0
    1303:	8d 50 01             	lea    0x1(%rax),%edx
    1306:	f2 41 0f 11 04 ce    	movsd  %xmm0,(%r14,%rcx,8)
    130c:	41 39 d5             	cmp    %edx,%r13d
    130f:	7e 50                	jle    1361 <main+0x201>
    1311:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1315:	48 63 ca             	movslq %edx,%rcx
    1318:	44 89 ef             	mov    %r13d,%edi
    131b:	83 c0 02             	add    $0x2,%eax
    131e:	f2 0f 2a c2          	cvtsi2sd %edx,%xmm0
    1322:	29 d7                	sub    %edx,%edi
    1324:	f2 41 0f 11 04 cc    	movsd  %xmm0,(%r12,%rcx,8)
    132a:	66 0f ef c0          	pxor   %xmm0,%xmm0
    132e:	f2 0f 2a c7          	cvtsi2sd %edi,%xmm0
    1332:	f2 41 0f 11 04 ce    	movsd  %xmm0,(%r14,%rcx,8)
    1338:	41 39 c5             	cmp    %eax,%r13d
    133b:	7e 24                	jle    1361 <main+0x201>
    133d:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1341:	48 63 d0             	movslq %eax,%rdx
    1344:	44 89 e9             	mov    %r13d,%ecx
    1347:	f2 0f 2a c0          	cvtsi2sd %eax,%xmm0
    134b:	29 c1                	sub    %eax,%ecx
    134d:	f2 41 0f 11 04 d4    	movsd  %xmm0,(%r12,%rdx,8)
    1353:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1357:	f2 0f 2a c1          	cvtsi2sd %ecx,%xmm0
    135b:	f2 41 0f 11 04 d6    	movsd  %xmm0,(%r14,%rdx,8)
    1361:	e8 ea fd ff ff       	callq  1150 <drand48@plt>
    1366:	f2 0f 11 45 b0       	movsd  %xmm0,-0x50(%rbp)
    136b:	e8 60 fd ff ff       	callq  10d0 <omp_get_wtime@plt>
    1370:	45 85 ed             	test   %r13d,%r13d
    1373:	ba 01 00 00 00       	mov    $0x1,%edx
    1378:	41 0f 4f d5          	cmovg  %r13d,%edx
    137c:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
    1381:	7e 3f                	jle    13c2 <main+0x262>
    1383:	41 83 fd 01          	cmp    $0x1,%r13d
    1387:	74 39                	je     13c2 <main+0x262>
    1389:	f2 0f 10 4d b0       	movsd  -0x50(%rbp),%xmm1
    138e:	d1 ea                	shr    %edx
    1390:	31 c0                	xor    %eax,%eax
    1392:	48 c1 e2 04          	shl    $0x4,%rdx
    1396:	66 0f 14 c9          	unpcklpd %xmm1,%xmm1
    139a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    13a0:	66 41 0f 10 04 06    	movupd (%r14,%rax,1),%xmm0
    13a6:	66 41 0f 10 14 04    	movupd (%r12,%rax,1),%xmm2
    13ac:	66 0f 59 c1          	mulpd  %xmm1,%xmm0
    13b0:	66 0f 58 c2          	addpd  %xmm2,%xmm0
    13b4:	41 0f 11 04 04       	movups %xmm0,(%r12,%rax,1)
    13b9:	48 83 c0 10          	add    $0x10,%rax
    13bd:	48 39 d0             	cmp    %rdx,%rax
    13c0:	75 de                	jne    13a0 <main+0x240>
    13c2:	e8 09 fd ff ff       	callq  10d0 <omp_get_wtime@plt>
    13c7:	f2 0f 5c 45 b8       	subsd  -0x48(%rbp),%xmm0
    13cc:	bf 01 00 00 00       	mov    $0x1,%edi
    13d1:	48 8d 35 50 0c 00 00 	lea    0xc50(%rip),%rsi        # 2028 <_IO_stdin_used+0x28>
    13d8:	b8 01 00 00 00       	mov    $0x1,%eax
    13dd:	e8 3e fd ff ff       	callq  1120 <__printf_chk@plt>
    13e2:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    13e6:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    13ed:	00 00 
    13ef:	0f 85 a9 00 00 00    	jne    149e <main+0x33e>
    13f5:	48 8d 65 d8          	lea    -0x28(%rbp),%rsp
    13f9:	31 c0                	xor    %eax,%eax
    13fb:	5b                   	pop    %rbx
    13fc:	41 5c                	pop    %r12
    13fe:	41 5d                	pop    %r13
    1400:	41 5e                	pop    %r14
    1402:	41 5f                	pop    %r15
    1404:	5d                   	pop    %rbp
    1405:	c3                   	retq   
    1406:	45 8d 7d ff          	lea    -0x1(%r13),%r15d
    140a:	31 db                	xor    %ebx,%ebx
    140c:	0f 1f 40 00          	nopl   0x0(%rax)
    1410:	e8 3b fd ff ff       	callq  1150 <drand48@plt>
    1415:	f2 41 0f 11 04 dc    	movsd  %xmm0,(%r12,%rbx,8)
    141b:	e8 30 fd ff ff       	callq  1150 <drand48@plt>
    1420:	48 89 d8             	mov    %rbx,%rax
    1423:	f2 41 0f 11 04 de    	movsd  %xmm0,(%r14,%rbx,8)
    1429:	48 83 c3 01          	add    $0x1,%rbx
    142d:	49 39 c7             	cmp    %rax,%r15
    1430:	75 de                	jne    1410 <main+0x2b0>
    1432:	e9 2a ff ff ff       	jmpq   1361 <main+0x201>
    1437:	e8 14 fd ff ff       	callq  1150 <drand48@plt>
    143c:	f2 0f 11 45 b0       	movsd  %xmm0,-0x50(%rbp)
    1441:	e8 8a fc ff ff       	callq  10d0 <omp_get_wtime@plt>
    1446:	44 89 ea             	mov    %r13d,%edx
    1449:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
    144e:	e9 36 ff ff ff       	jmpq   1389 <main+0x229>
    1453:	e8 f8 fc ff ff       	callq  1150 <drand48@plt>
    1458:	e8 73 fc ff ff       	callq  10d0 <omp_get_wtime@plt>
    145d:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
    1462:	e9 5b ff ff ff       	jmpq   13c2 <main+0x262>
    1467:	48 83 4c 14 f8 00    	orq    $0x0,-0x8(%rsp,%rdx,1)
    146d:	e9 d4 fd ff ff       	jmpq   1246 <main+0xe6>
    1472:	31 c0                	xor    %eax,%eax
    1474:	e9 6c fe ff ff       	jmpq   12e5 <main+0x185>
    1479:	48 8b 0d a0 2b 00 00 	mov    0x2ba0(%rip),%rcx        # 4020 <stderr@@GLIBC_2.2.5>
    1480:	ba 1f 00 00 00       	mov    $0x1f,%edx
    1485:	be 01 00 00 00       	mov    $0x1,%esi
    148a:	48 8d 3d 77 0b 00 00 	lea    0xb77(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    1491:	e8 aa fc ff ff       	callq  1140 <fwrite@plt>
    1496:	83 cf ff             	or     $0xffffffff,%edi
    1499:	e8 92 fc ff ff       	callq  1130 <exit@plt>
    149e:	e8 3d fc ff ff       	callq  10e0 <__stack_chk_fail@plt>
    14a3:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    14aa:	00 00 00 
    14ad:	0f 1f 00             	nopl   (%rax)

00000000000014b0 <_start>:
    14b0:	f3 0f 1e fa          	endbr64 
    14b4:	31 ed                	xor    %ebp,%ebp
    14b6:	49 89 d1             	mov    %rdx,%r9
    14b9:	5e                   	pop    %rsi
    14ba:	48 89 e2             	mov    %rsp,%rdx
    14bd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    14c1:	50                   	push   %rax
    14c2:	54                   	push   %rsp
    14c3:	4c 8d 05 46 01 00 00 	lea    0x146(%rip),%r8        # 1610 <__libc_csu_fini>
    14ca:	48 8d 0d cf 00 00 00 	lea    0xcf(%rip),%rcx        # 15a0 <__libc_csu_init>
    14d1:	48 8d 3d 88 fc ff ff 	lea    -0x378(%rip),%rdi        # 1160 <main>
    14d8:	ff 15 02 2b 00 00    	callq  *0x2b02(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    14de:	f4                   	hlt    
    14df:	90                   	nop

00000000000014e0 <deregister_tm_clones>:
    14e0:	48 8d 3d 29 2b 00 00 	lea    0x2b29(%rip),%rdi        # 4010 <__TMC_END__>
    14e7:	48 8d 05 22 2b 00 00 	lea    0x2b22(%rip),%rax        # 4010 <__TMC_END__>
    14ee:	48 39 f8             	cmp    %rdi,%rax
    14f1:	74 15                	je     1508 <deregister_tm_clones+0x28>
    14f3:	48 8b 05 de 2a 00 00 	mov    0x2ade(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    14fa:	48 85 c0             	test   %rax,%rax
    14fd:	74 09                	je     1508 <deregister_tm_clones+0x28>
    14ff:	ff e0                	jmpq   *%rax
    1501:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1508:	c3                   	retq   
    1509:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001510 <register_tm_clones>:
    1510:	48 8d 3d f9 2a 00 00 	lea    0x2af9(%rip),%rdi        # 4010 <__TMC_END__>
    1517:	48 8d 35 f2 2a 00 00 	lea    0x2af2(%rip),%rsi        # 4010 <__TMC_END__>
    151e:	48 29 fe             	sub    %rdi,%rsi
    1521:	48 89 f0             	mov    %rsi,%rax
    1524:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1528:	48 c1 f8 03          	sar    $0x3,%rax
    152c:	48 01 c6             	add    %rax,%rsi
    152f:	48 d1 fe             	sar    %rsi
    1532:	74 14                	je     1548 <register_tm_clones+0x38>
    1534:	48 8b 05 b5 2a 00 00 	mov    0x2ab5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    153b:	48 85 c0             	test   %rax,%rax
    153e:	74 08                	je     1548 <register_tm_clones+0x38>
    1540:	ff e0                	jmpq   *%rax
    1542:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1548:	c3                   	retq   
    1549:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001550 <__do_global_dtors_aux>:
    1550:	f3 0f 1e fa          	endbr64 
    1554:	80 3d cd 2a 00 00 00 	cmpb   $0x0,0x2acd(%rip)        # 4028 <completed.8060>
    155b:	75 2b                	jne    1588 <__do_global_dtors_aux+0x38>
    155d:	55                   	push   %rbp
    155e:	48 83 3d 92 2a 00 00 	cmpq   $0x0,0x2a92(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1565:	00 
    1566:	48 89 e5             	mov    %rsp,%rbp
    1569:	74 0c                	je     1577 <__do_global_dtors_aux+0x27>
    156b:	48 8b 3d 96 2a 00 00 	mov    0x2a96(%rip),%rdi        # 4008 <__dso_handle>
    1572:	e8 49 fb ff ff       	callq  10c0 <__cxa_finalize@plt>
    1577:	e8 64 ff ff ff       	callq  14e0 <deregister_tm_clones>
    157c:	c6 05 a5 2a 00 00 01 	movb   $0x1,0x2aa5(%rip)        # 4028 <completed.8060>
    1583:	5d                   	pop    %rbp
    1584:	c3                   	retq   
    1585:	0f 1f 00             	nopl   (%rax)
    1588:	c3                   	retq   
    1589:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001590 <frame_dummy>:
    1590:	f3 0f 1e fa          	endbr64 
    1594:	e9 77 ff ff ff       	jmpq   1510 <register_tm_clones>
    1599:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000015a0 <__libc_csu_init>:
    15a0:	f3 0f 1e fa          	endbr64 
    15a4:	41 57                	push   %r15
    15a6:	4c 8d 3d bb 27 00 00 	lea    0x27bb(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    15ad:	41 56                	push   %r14
    15af:	49 89 d6             	mov    %rdx,%r14
    15b2:	41 55                	push   %r13
    15b4:	49 89 f5             	mov    %rsi,%r13
    15b7:	41 54                	push   %r12
    15b9:	41 89 fc             	mov    %edi,%r12d
    15bc:	55                   	push   %rbp
    15bd:	48 8d 2d ac 27 00 00 	lea    0x27ac(%rip),%rbp        # 3d70 <__do_global_dtors_aux_fini_array_entry>
    15c4:	53                   	push   %rbx
    15c5:	4c 29 fd             	sub    %r15,%rbp
    15c8:	48 83 ec 08          	sub    $0x8,%rsp
    15cc:	e8 2f fa ff ff       	callq  1000 <_init>
    15d1:	48 c1 fd 03          	sar    $0x3,%rbp
    15d5:	74 1f                	je     15f6 <__libc_csu_init+0x56>
    15d7:	31 db                	xor    %ebx,%ebx
    15d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    15e0:	4c 89 f2             	mov    %r14,%rdx
    15e3:	4c 89 ee             	mov    %r13,%rsi
    15e6:	44 89 e7             	mov    %r12d,%edi
    15e9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    15ed:	48 83 c3 01          	add    $0x1,%rbx
    15f1:	48 39 dd             	cmp    %rbx,%rbp
    15f4:	75 ea                	jne    15e0 <__libc_csu_init+0x40>
    15f6:	48 83 c4 08          	add    $0x8,%rsp
    15fa:	5b                   	pop    %rbx
    15fb:	5d                   	pop    %rbp
    15fc:	41 5c                	pop    %r12
    15fe:	41 5d                	pop    %r13
    1600:	41 5e                	pop    %r14
    1602:	41 5f                	pop    %r15
    1604:	c3                   	retq   
    1605:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    160c:	00 00 00 00 

0000000000001610 <__libc_csu_fini>:
    1610:	f3 0f 1e fa          	endbr64 
    1614:	c3                   	retq   

Desensamblado de la sección .fini:

0000000000001618 <_fini>:
    1618:	f3 0f 1e fa          	endbr64 
    161c:	48 83 ec 08          	sub    $0x8,%rsp
    1620:	48 83 c4 08          	add    $0x8,%rsp
    1624:	c3                   	retq   
