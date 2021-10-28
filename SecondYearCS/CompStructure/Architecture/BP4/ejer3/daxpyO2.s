
daxpyO2:     formato del fichero elf64-x86-64


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
    1187:	0f 8e d2 01 00 00    	jle    135f <main+0x1ff>
    118d:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    1191:	ba 0a 00 00 00       	mov    $0xa,%edx
    1196:	31 f6                	xor    %esi,%esi
    1198:	e8 53 ff ff ff       	callq  10f0 <strtol@plt>
    119d:	48 89 e6             	mov    %rsp,%rsi
    11a0:	49 89 c4             	mov    %rax,%r12
    11a3:	41 89 c6             	mov    %eax,%r14d
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
    11ed:	75 30                	jne    121f <main+0xbf>
    11ef:	48 89 c2             	mov    %rax,%rdx
    11f2:	48 89 e1             	mov    %rsp,%rcx
    11f5:	48 25 00 f0 ff ff    	and    $0xfffffffffffff000,%rax
    11fb:	48 89 e3             	mov    %rsp,%rbx
    11fe:	48 29 c1             	sub    %rax,%rcx
    1201:	48 83 e2 f0          	and    $0xfffffffffffffff0,%rdx
    1205:	48 89 c8             	mov    %rcx,%rax
    1208:	48 39 c4             	cmp    %rax,%rsp
    120b:	74 1a                	je     1227 <main+0xc7>
    120d:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1214:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    121b:	00 00 
    121d:	eb e9                	jmp    1208 <main+0xa8>
    121f:	48 83 4c 14 f8 00    	orq    $0x0,-0x8(%rsp,%rdx,1)
    1225:	eb c8                	jmp    11ef <main+0x8f>
    1227:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    122d:	48 29 d4             	sub    %rdx,%rsp
    1230:	48 85 d2             	test   %rdx,%rdx
    1233:	0f 85 1b 01 00 00    	jne    1354 <main+0x1f4>
    1239:	31 ff                	xor    %edi,%edi
    123b:	49 89 e5             	mov    %rsp,%r13
    123e:	e8 bd fe ff ff       	callq  1100 <time@plt>
    1243:	48 89 c7             	mov    %rax,%rdi
    1246:	e8 c5 fe ff ff       	callq  1110 <srand48@plt>
    124b:	41 83 fc 07          	cmp    $0x7,%r12d
    124f:	0f 8f b5 00 00 00    	jg     130a <main+0x1aa>
    1255:	45 85 e4             	test   %r12d,%r12d
    1258:	0f 8e e2 00 00 00    	jle    1340 <main+0x1e0>
    125e:	31 c0                	xor    %eax,%eax
    1260:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1264:	44 89 e2             	mov    %r12d,%edx
    1267:	f2 0f 2a c0          	cvtsi2sd %eax,%xmm0
    126b:	29 c2                	sub    %eax,%edx
    126d:	f2 0f 11 04 c3       	movsd  %xmm0,(%rbx,%rax,8)
    1272:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1276:	f2 0f 2a c2          	cvtsi2sd %edx,%xmm0
    127a:	f2 41 0f 11 44 c5 00 	movsd  %xmm0,0x0(%r13,%rax,8)
    1281:	48 83 c0 01          	add    $0x1,%rax
    1285:	41 39 c6             	cmp    %eax,%r14d
    1288:	7f d6                	jg     1260 <main+0x100>
    128a:	e8 c1 fe ff ff       	callq  1150 <drand48@plt>
    128f:	f2 0f 11 45 b0       	movsd  %xmm0,-0x50(%rbp)
    1294:	e8 37 fe ff ff       	callq  10d0 <omp_get_wtime@plt>
    1299:	f2 0f 10 4d b0       	movsd  -0x50(%rbp),%xmm1
    129e:	31 c0                	xor    %eax,%eax
    12a0:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
    12a5:	0f 1f 00             	nopl   (%rax)
    12a8:	f2 41 0f 10 44 c5 00 	movsd  0x0(%r13,%rax,8),%xmm0
    12af:	f2 0f 59 c1          	mulsd  %xmm1,%xmm0
    12b3:	f2 0f 58 04 c3       	addsd  (%rbx,%rax,8),%xmm0
    12b8:	f2 0f 11 04 c3       	movsd  %xmm0,(%rbx,%rax,8)
    12bd:	48 83 c0 01          	add    $0x1,%rax
    12c1:	41 39 c6             	cmp    %eax,%r14d
    12c4:	7f e2                	jg     12a8 <main+0x148>
    12c6:	e8 05 fe ff ff       	callq  10d0 <omp_get_wtime@plt>
    12cb:	f2 0f 5c 45 b8       	subsd  -0x48(%rbp),%xmm0
    12d0:	bf 01 00 00 00       	mov    $0x1,%edi
    12d5:	48 8d 35 4c 0d 00 00 	lea    0xd4c(%rip),%rsi        # 2028 <_IO_stdin_used+0x28>
    12dc:	b8 01 00 00 00       	mov    $0x1,%eax
    12e1:	e8 3a fe ff ff       	callq  1120 <__printf_chk@plt>
    12e6:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    12ea:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    12f1:	00 00 
    12f3:	0f 85 8b 00 00 00    	jne    1384 <main+0x224>
    12f9:	48 8d 65 d8          	lea    -0x28(%rbp),%rsp
    12fd:	31 c0                	xor    %eax,%eax
    12ff:	5b                   	pop    %rbx
    1300:	41 5c                	pop    %r12
    1302:	41 5d                	pop    %r13
    1304:	41 5e                	pop    %r14
    1306:	41 5f                	pop    %r15
    1308:	5d                   	pop    %rbp
    1309:	c3                   	retq   
    130a:	45 8d 7c 24 ff       	lea    -0x1(%r12),%r15d
    130f:	45 31 e4             	xor    %r12d,%r12d
    1312:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1318:	e8 33 fe ff ff       	callq  1150 <drand48@plt>
    131d:	f2 42 0f 11 04 e3    	movsd  %xmm0,(%rbx,%r12,8)
    1323:	e8 28 fe ff ff       	callq  1150 <drand48@plt>
    1328:	4c 89 e0             	mov    %r12,%rax
    132b:	f2 43 0f 11 44 e5 00 	movsd  %xmm0,0x0(%r13,%r12,8)
    1332:	49 83 c4 01          	add    $0x1,%r12
    1336:	4c 39 f8             	cmp    %r15,%rax
    1339:	75 dd                	jne    1318 <main+0x1b8>
    133b:	e9 4a ff ff ff       	jmpq   128a <main+0x12a>
    1340:	e8 0b fe ff ff       	callq  1150 <drand48@plt>
    1345:	e8 86 fd ff ff       	callq  10d0 <omp_get_wtime@plt>
    134a:	f2 0f 11 45 b8       	movsd  %xmm0,-0x48(%rbp)
    134f:	e9 72 ff ff ff       	jmpq   12c6 <main+0x166>
    1354:	48 83 4c 14 f8 00    	orq    $0x0,-0x8(%rsp,%rdx,1)
    135a:	e9 da fe ff ff       	jmpq   1239 <main+0xd9>
    135f:	48 8b 0d ba 2c 00 00 	mov    0x2cba(%rip),%rcx        # 4020 <stderr@@GLIBC_2.2.5>
    1366:	ba 1f 00 00 00       	mov    $0x1f,%edx
    136b:	be 01 00 00 00       	mov    $0x1,%esi
    1370:	48 8d 3d 91 0c 00 00 	lea    0xc91(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    1377:	e8 c4 fd ff ff       	callq  1140 <fwrite@plt>
    137c:	83 cf ff             	or     $0xffffffff,%edi
    137f:	e8 ac fd ff ff       	callq  1130 <exit@plt>
    1384:	e8 57 fd ff ff       	callq  10e0 <__stack_chk_fail@plt>
    1389:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001390 <_start>:
    1390:	f3 0f 1e fa          	endbr64 
    1394:	31 ed                	xor    %ebp,%ebp
    1396:	49 89 d1             	mov    %rdx,%r9
    1399:	5e                   	pop    %rsi
    139a:	48 89 e2             	mov    %rsp,%rdx
    139d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    13a1:	50                   	push   %rax
    13a2:	54                   	push   %rsp
    13a3:	4c 8d 05 46 01 00 00 	lea    0x146(%rip),%r8        # 14f0 <__libc_csu_fini>
    13aa:	48 8d 0d cf 00 00 00 	lea    0xcf(%rip),%rcx        # 1480 <__libc_csu_init>
    13b1:	48 8d 3d a8 fd ff ff 	lea    -0x258(%rip),%rdi        # 1160 <main>
    13b8:	ff 15 22 2c 00 00    	callq  *0x2c22(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    13be:	f4                   	hlt    
    13bf:	90                   	nop

00000000000013c0 <deregister_tm_clones>:
    13c0:	48 8d 3d 49 2c 00 00 	lea    0x2c49(%rip),%rdi        # 4010 <__TMC_END__>
    13c7:	48 8d 05 42 2c 00 00 	lea    0x2c42(%rip),%rax        # 4010 <__TMC_END__>
    13ce:	48 39 f8             	cmp    %rdi,%rax
    13d1:	74 15                	je     13e8 <deregister_tm_clones+0x28>
    13d3:	48 8b 05 fe 2b 00 00 	mov    0x2bfe(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    13da:	48 85 c0             	test   %rax,%rax
    13dd:	74 09                	je     13e8 <deregister_tm_clones+0x28>
    13df:	ff e0                	jmpq   *%rax
    13e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    13e8:	c3                   	retq   
    13e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000013f0 <register_tm_clones>:
    13f0:	48 8d 3d 19 2c 00 00 	lea    0x2c19(%rip),%rdi        # 4010 <__TMC_END__>
    13f7:	48 8d 35 12 2c 00 00 	lea    0x2c12(%rip),%rsi        # 4010 <__TMC_END__>
    13fe:	48 29 fe             	sub    %rdi,%rsi
    1401:	48 89 f0             	mov    %rsi,%rax
    1404:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1408:	48 c1 f8 03          	sar    $0x3,%rax
    140c:	48 01 c6             	add    %rax,%rsi
    140f:	48 d1 fe             	sar    %rsi
    1412:	74 14                	je     1428 <register_tm_clones+0x38>
    1414:	48 8b 05 d5 2b 00 00 	mov    0x2bd5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    141b:	48 85 c0             	test   %rax,%rax
    141e:	74 08                	je     1428 <register_tm_clones+0x38>
    1420:	ff e0                	jmpq   *%rax
    1422:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1428:	c3                   	retq   
    1429:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001430 <__do_global_dtors_aux>:
    1430:	f3 0f 1e fa          	endbr64 
    1434:	80 3d ed 2b 00 00 00 	cmpb   $0x0,0x2bed(%rip)        # 4028 <completed.8060>
    143b:	75 2b                	jne    1468 <__do_global_dtors_aux+0x38>
    143d:	55                   	push   %rbp
    143e:	48 83 3d b2 2b 00 00 	cmpq   $0x0,0x2bb2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1445:	00 
    1446:	48 89 e5             	mov    %rsp,%rbp
    1449:	74 0c                	je     1457 <__do_global_dtors_aux+0x27>
    144b:	48 8b 3d b6 2b 00 00 	mov    0x2bb6(%rip),%rdi        # 4008 <__dso_handle>
    1452:	e8 69 fc ff ff       	callq  10c0 <__cxa_finalize@plt>
    1457:	e8 64 ff ff ff       	callq  13c0 <deregister_tm_clones>
    145c:	c6 05 c5 2b 00 00 01 	movb   $0x1,0x2bc5(%rip)        # 4028 <completed.8060>
    1463:	5d                   	pop    %rbp
    1464:	c3                   	retq   
    1465:	0f 1f 00             	nopl   (%rax)
    1468:	c3                   	retq   
    1469:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001470 <frame_dummy>:
    1470:	f3 0f 1e fa          	endbr64 
    1474:	e9 77 ff ff ff       	jmpq   13f0 <register_tm_clones>
    1479:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001480 <__libc_csu_init>:
    1480:	f3 0f 1e fa          	endbr64 
    1484:	41 57                	push   %r15
    1486:	4c 8d 3d db 28 00 00 	lea    0x28db(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    148d:	41 56                	push   %r14
    148f:	49 89 d6             	mov    %rdx,%r14
    1492:	41 55                	push   %r13
    1494:	49 89 f5             	mov    %rsi,%r13
    1497:	41 54                	push   %r12
    1499:	41 89 fc             	mov    %edi,%r12d
    149c:	55                   	push   %rbp
    149d:	48 8d 2d cc 28 00 00 	lea    0x28cc(%rip),%rbp        # 3d70 <__do_global_dtors_aux_fini_array_entry>
    14a4:	53                   	push   %rbx
    14a5:	4c 29 fd             	sub    %r15,%rbp
    14a8:	48 83 ec 08          	sub    $0x8,%rsp
    14ac:	e8 4f fb ff ff       	callq  1000 <_init>
    14b1:	48 c1 fd 03          	sar    $0x3,%rbp
    14b5:	74 1f                	je     14d6 <__libc_csu_init+0x56>
    14b7:	31 db                	xor    %ebx,%ebx
    14b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    14c0:	4c 89 f2             	mov    %r14,%rdx
    14c3:	4c 89 ee             	mov    %r13,%rsi
    14c6:	44 89 e7             	mov    %r12d,%edi
    14c9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    14cd:	48 83 c3 01          	add    $0x1,%rbx
    14d1:	48 39 dd             	cmp    %rbx,%rbp
    14d4:	75 ea                	jne    14c0 <__libc_csu_init+0x40>
    14d6:	48 83 c4 08          	add    $0x8,%rsp
    14da:	5b                   	pop    %rbx
    14db:	5d                   	pop    %rbp
    14dc:	41 5c                	pop    %r12
    14de:	41 5d                	pop    %r13
    14e0:	41 5e                	pop    %r14
    14e2:	41 5f                	pop    %r15
    14e4:	c3                   	retq   
    14e5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    14ec:	00 00 00 00 

00000000000014f0 <__libc_csu_fini>:
    14f0:	f3 0f 1e fa          	endbr64 
    14f4:	c3                   	retq   

Desensamblado de la sección .fini:

00000000000014f8 <_fini>:
    14f8:	f3 0f 1e fa          	endbr64 
    14fc:	48 83 ec 08          	sub    $0x8,%rsp
    1500:	48 83 c4 08          	add    $0x8,%rsp
    1504:	c3                   	retq   
