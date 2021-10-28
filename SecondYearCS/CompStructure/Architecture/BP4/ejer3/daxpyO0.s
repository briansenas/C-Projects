
daxpyO0:     formato del fichero elf64-x86-64


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

00000000000010f0 <printf@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 a5 2e 00 00 	bnd jmpq *0x2ea5(%rip)        # 3fa0 <printf@GLIBC_2.2.5>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001100 <time@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 9d 2e 00 00 	bnd jmpq *0x2e9d(%rip)        # 3fa8 <time@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001110 <srand48@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 95 2e 00 00 	bnd jmpq *0x2e95(%rip)        # 3fb0 <srand48@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001120 <atoi@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 8d 2e 00 00 	bnd jmpq *0x2e8d(%rip)        # 3fb8 <atoi@GLIBC_2.2.5>
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

0000000000001160 <_start>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	31 ed                	xor    %ebp,%ebp
    1166:	49 89 d1             	mov    %rdx,%r9
    1169:	5e                   	pop    %rsi
    116a:	48 89 e2             	mov    %rsp,%rdx
    116d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1171:	50                   	push   %rax
    1172:	54                   	push   %rsp
    1173:	4c 8d 05 a6 04 00 00 	lea    0x4a6(%rip),%r8        # 1620 <__libc_csu_fini>
    117a:	48 8d 0d 2f 04 00 00 	lea    0x42f(%rip),%rcx        # 15b0 <__libc_csu_init>
    1181:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 1249 <main>
    1188:	ff 15 52 2e 00 00    	callq  *0x2e52(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    118e:	f4                   	hlt    
    118f:	90                   	nop

0000000000001190 <deregister_tm_clones>:
    1190:	48 8d 3d 79 2e 00 00 	lea    0x2e79(%rip),%rdi        # 4010 <__TMC_END__>
    1197:	48 8d 05 72 2e 00 00 	lea    0x2e72(%rip),%rax        # 4010 <__TMC_END__>
    119e:	48 39 f8             	cmp    %rdi,%rax
    11a1:	74 15                	je     11b8 <deregister_tm_clones+0x28>
    11a3:	48 8b 05 2e 2e 00 00 	mov    0x2e2e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    11aa:	48 85 c0             	test   %rax,%rax
    11ad:	74 09                	je     11b8 <deregister_tm_clones+0x28>
    11af:	ff e0                	jmpq   *%rax
    11b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    11b8:	c3                   	retq   
    11b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011c0 <register_tm_clones>:
    11c0:	48 8d 3d 49 2e 00 00 	lea    0x2e49(%rip),%rdi        # 4010 <__TMC_END__>
    11c7:	48 8d 35 42 2e 00 00 	lea    0x2e42(%rip),%rsi        # 4010 <__TMC_END__>
    11ce:	48 29 fe             	sub    %rdi,%rsi
    11d1:	48 89 f0             	mov    %rsi,%rax
    11d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    11d8:	48 c1 f8 03          	sar    $0x3,%rax
    11dc:	48 01 c6             	add    %rax,%rsi
    11df:	48 d1 fe             	sar    %rsi
    11e2:	74 14                	je     11f8 <register_tm_clones+0x38>
    11e4:	48 8b 05 05 2e 00 00 	mov    0x2e05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    11eb:	48 85 c0             	test   %rax,%rax
    11ee:	74 08                	je     11f8 <register_tm_clones+0x38>
    11f0:	ff e0                	jmpq   *%rax
    11f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    11f8:	c3                   	retq   
    11f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001200 <__do_global_dtors_aux>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	80 3d 1d 2e 00 00 00 	cmpb   $0x0,0x2e1d(%rip)        # 4028 <completed.8060>
    120b:	75 2b                	jne    1238 <__do_global_dtors_aux+0x38>
    120d:	55                   	push   %rbp
    120e:	48 83 3d e2 2d 00 00 	cmpq   $0x0,0x2de2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1215:	00 
    1216:	48 89 e5             	mov    %rsp,%rbp
    1219:	74 0c                	je     1227 <__do_global_dtors_aux+0x27>
    121b:	48 8b 3d e6 2d 00 00 	mov    0x2de6(%rip),%rdi        # 4008 <__dso_handle>
    1222:	e8 99 fe ff ff       	callq  10c0 <__cxa_finalize@plt>
    1227:	e8 64 ff ff ff       	callq  1190 <deregister_tm_clones>
    122c:	c6 05 f5 2d 00 00 01 	movb   $0x1,0x2df5(%rip)        # 4028 <completed.8060>
    1233:	5d                   	pop    %rbp
    1234:	c3                   	retq   
    1235:	0f 1f 00             	nopl   (%rax)
    1238:	c3                   	retq   
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <frame_dummy>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	e9 77 ff ff ff       	jmpq   11c0 <register_tm_clones>

0000000000001249 <main>:
    1249:	f3 0f 1e fa          	endbr64 
    124d:	55                   	push   %rbp
    124e:	48 89 e5             	mov    %rsp,%rbp
    1251:	41 57                	push   %r15
    1253:	41 56                	push   %r14
    1255:	41 55                	push   %r13
    1257:	41 54                	push   %r12
    1259:	53                   	push   %rbx
    125a:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
    1261:	89 bd 7c ff ff ff    	mov    %edi,-0x84(%rbp)
    1267:	48 89 b5 70 ff ff ff 	mov    %rsi,-0x90(%rbp)
    126e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1275:	00 00 
    1277:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    127b:	31 c0                	xor    %eax,%eax
    127d:	48 89 e0             	mov    %rsp,%rax
    1280:	48 89 c3             	mov    %rax,%rbx
    1283:	83 bd 7c ff ff ff 01 	cmpl   $0x1,-0x84(%rbp)
    128a:	7f 2a                	jg     12b6 <main+0x6d>
    128c:	48 8b 05 8d 2d 00 00 	mov    0x2d8d(%rip),%rax        # 4020 <stderr@@GLIBC_2.2.5>
    1293:	48 89 c1             	mov    %rax,%rcx
    1296:	ba 1f 00 00 00       	mov    $0x1f,%edx
    129b:	be 01 00 00 00       	mov    $0x1,%esi
    12a0:	48 8d 3d 61 0d 00 00 	lea    0xd61(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    12a7:	e8 94 fe ff ff       	callq  1140 <fwrite@plt>
    12ac:	bf ff ff ff ff       	mov    $0xffffffff,%edi
    12b1:	e8 7a fe ff ff       	callq  1130 <exit@plt>
    12b6:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
    12bd:	48 83 c0 08          	add    $0x8,%rax
    12c1:	48 8b 00             	mov    (%rax),%rax
    12c4:	48 89 c7             	mov    %rax,%rdi
    12c7:	e8 54 fe ff ff       	callq  1120 <atoi@plt>
    12cc:	89 45 8c             	mov    %eax,-0x74(%rbp)
    12cf:	8b 45 8c             	mov    -0x74(%rbp),%eax
    12d2:	48 63 d0             	movslq %eax,%rdx
    12d5:	48 83 ea 01          	sub    $0x1,%rdx
    12d9:	48 89 55 90          	mov    %rdx,-0x70(%rbp)
    12dd:	48 63 d0             	movslq %eax,%rdx
    12e0:	48 89 95 60 ff ff ff 	mov    %rdx,-0xa0(%rbp)
    12e7:	48 c7 85 68 ff ff ff 	movq   $0x0,-0x98(%rbp)
    12ee:	00 00 00 00 
    12f2:	48 63 d0             	movslq %eax,%rdx
    12f5:	48 89 95 50 ff ff ff 	mov    %rdx,-0xb0(%rbp)
    12fc:	48 c7 85 58 ff ff ff 	movq   $0x0,-0xa8(%rbp)
    1303:	00 00 00 00 
    1307:	48 98                	cltq   
    1309:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    1310:	00 
    1311:	b8 10 00 00 00       	mov    $0x10,%eax
    1316:	48 83 e8 01          	sub    $0x1,%rax
    131a:	48 01 d0             	add    %rdx,%rax
    131d:	bf 10 00 00 00       	mov    $0x10,%edi
    1322:	ba 00 00 00 00       	mov    $0x0,%edx
    1327:	48 f7 f7             	div    %rdi
    132a:	48 6b c0 10          	imul   $0x10,%rax,%rax
    132e:	48 89 c2             	mov    %rax,%rdx
    1331:	48 81 e2 00 f0 ff ff 	and    $0xfffffffffffff000,%rdx
    1338:	48 89 e6             	mov    %rsp,%rsi
    133b:	48 29 d6             	sub    %rdx,%rsi
    133e:	48 89 f2             	mov    %rsi,%rdx
    1341:	48 39 d4             	cmp    %rdx,%rsp
    1344:	74 12                	je     1358 <main+0x10f>
    1346:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    134d:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    1354:	00 00 
    1356:	eb e9                	jmp    1341 <main+0xf8>
    1358:	48 89 c2             	mov    %rax,%rdx
    135b:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    1361:	48 29 d4             	sub    %rdx,%rsp
    1364:	48 89 c2             	mov    %rax,%rdx
    1367:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    136d:	48 85 d2             	test   %rdx,%rdx
    1370:	74 10                	je     1382 <main+0x139>
    1372:	25 ff 0f 00 00       	and    $0xfff,%eax
    1377:	48 83 e8 08          	sub    $0x8,%rax
    137b:	48 01 e0             	add    %rsp,%rax
    137e:	48 83 08 00          	orq    $0x0,(%rax)
    1382:	48 89 e0             	mov    %rsp,%rax
    1385:	48 83 c0 07          	add    $0x7,%rax
    1389:	48 c1 e8 03          	shr    $0x3,%rax
    138d:	48 c1 e0 03          	shl    $0x3,%rax
    1391:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    1395:	8b 45 8c             	mov    -0x74(%rbp),%eax
    1398:	48 63 d0             	movslq %eax,%rdx
    139b:	48 83 ea 01          	sub    $0x1,%rdx
    139f:	48 89 55 a0          	mov    %rdx,-0x60(%rbp)
    13a3:	48 63 d0             	movslq %eax,%rdx
    13a6:	49 89 d6             	mov    %rdx,%r14
    13a9:	41 bf 00 00 00 00    	mov    $0x0,%r15d
    13af:	48 63 d0             	movslq %eax,%rdx
    13b2:	49 89 d4             	mov    %rdx,%r12
    13b5:	41 bd 00 00 00 00    	mov    $0x0,%r13d
    13bb:	48 98                	cltq   
    13bd:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    13c4:	00 
    13c5:	b8 10 00 00 00       	mov    $0x10,%eax
    13ca:	48 83 e8 01          	sub    $0x1,%rax
    13ce:	48 01 d0             	add    %rdx,%rax
    13d1:	be 10 00 00 00       	mov    $0x10,%esi
    13d6:	ba 00 00 00 00       	mov    $0x0,%edx
    13db:	48 f7 f6             	div    %rsi
    13de:	48 6b c0 10          	imul   $0x10,%rax,%rax
    13e2:	48 89 c2             	mov    %rax,%rdx
    13e5:	48 81 e2 00 f0 ff ff 	and    $0xfffffffffffff000,%rdx
    13ec:	48 89 e6             	mov    %rsp,%rsi
    13ef:	48 29 d6             	sub    %rdx,%rsi
    13f2:	48 89 f2             	mov    %rsi,%rdx
    13f5:	48 39 d4             	cmp    %rdx,%rsp
    13f8:	74 12                	je     140c <main+0x1c3>
    13fa:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1401:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    1408:	00 00 
    140a:	eb e9                	jmp    13f5 <main+0x1ac>
    140c:	48 89 c2             	mov    %rax,%rdx
    140f:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    1415:	48 29 d4             	sub    %rdx,%rsp
    1418:	48 89 c2             	mov    %rax,%rdx
    141b:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    1421:	48 85 d2             	test   %rdx,%rdx
    1424:	74 10                	je     1436 <main+0x1ed>
    1426:	25 ff 0f 00 00       	and    $0xfff,%eax
    142b:	48 83 e8 08          	sub    $0x8,%rax
    142f:	48 01 e0             	add    %rsp,%rax
    1432:	48 83 08 00          	orq    $0x0,(%rax)
    1436:	48 89 e0             	mov    %rsp,%rax
    1439:	48 83 c0 07          	add    $0x7,%rax
    143d:	48 c1 e8 03          	shr    $0x3,%rax
    1441:	48 c1 e0 03          	shl    $0x3,%rax
    1445:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    1449:	bf 00 00 00 00       	mov    $0x0,%edi
    144e:	e8 ad fc ff ff       	callq  1100 <time@plt>
    1453:	48 89 c7             	mov    %rax,%rdi
    1456:	e8 b5 fc ff ff       	callq  1110 <srand48@plt>
    145b:	83 7d 8c 07          	cmpl   $0x7,-0x74(%rbp)
    145f:	7f 44                	jg     14a5 <main+0x25c>
    1461:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    1468:	eb 31                	jmp    149b <main+0x252>
    146a:	f2 0f 2a 45 88       	cvtsi2sdl -0x78(%rbp),%xmm0
    146f:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    1473:	8b 55 88             	mov    -0x78(%rbp),%edx
    1476:	48 63 d2             	movslq %edx,%rdx
    1479:	f2 0f 11 04 d0       	movsd  %xmm0,(%rax,%rdx,8)
    147e:	8b 45 8c             	mov    -0x74(%rbp),%eax
    1481:	2b 45 88             	sub    -0x78(%rbp),%eax
    1484:	f2 0f 2a c0          	cvtsi2sd %eax,%xmm0
    1488:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    148c:	8b 55 88             	mov    -0x78(%rbp),%edx
    148f:	48 63 d2             	movslq %edx,%rdx
    1492:	f2 0f 11 04 d0       	movsd  %xmm0,(%rax,%rdx,8)
    1497:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    149b:	8b 45 88             	mov    -0x78(%rbp),%eax
    149e:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    14a1:	7c c7                	jl     146a <main+0x221>
    14a3:	eb 45                	jmp    14ea <main+0x2a1>
    14a5:	c7 45 84 00 00 00 00 	movl   $0x0,-0x7c(%rbp)
    14ac:	eb 34                	jmp    14e2 <main+0x299>
    14ae:	e8 9d fc ff ff       	callq  1150 <drand48@plt>
    14b3:	66 48 0f 7e c0       	movq   %xmm0,%rax
    14b8:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    14bc:	8b 4d 84             	mov    -0x7c(%rbp),%ecx
    14bf:	48 63 c9             	movslq %ecx,%rcx
    14c2:	48 89 04 ca          	mov    %rax,(%rdx,%rcx,8)
    14c6:	e8 85 fc ff ff       	callq  1150 <drand48@plt>
    14cb:	66 48 0f 7e c0       	movq   %xmm0,%rax
    14d0:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    14d4:	8b 4d 84             	mov    -0x7c(%rbp),%ecx
    14d7:	48 63 c9             	movslq %ecx,%rcx
    14da:	48 89 04 ca          	mov    %rax,(%rdx,%rcx,8)
    14de:	83 45 84 01          	addl   $0x1,-0x7c(%rbp)
    14e2:	8b 45 84             	mov    -0x7c(%rbp),%eax
    14e5:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    14e8:	7c c4                	jl     14ae <main+0x265>
    14ea:	e8 61 fc ff ff       	callq  1150 <drand48@plt>
    14ef:	66 48 0f 7e c0       	movq   %xmm0,%rax
    14f4:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    14f8:	e8 d3 fb ff ff       	callq  10d0 <omp_get_wtime@plt>
    14fd:	66 48 0f 7e c0       	movq   %xmm0,%rax
    1502:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1506:	c7 45 80 00 00 00 00 	movl   $0x0,-0x80(%rbp)
    150d:	eb 3e                	jmp    154d <main+0x304>
    150f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    1513:	8b 55 80             	mov    -0x80(%rbp),%edx
    1516:	48 63 d2             	movslq %edx,%rdx
    1519:	f2 0f 10 04 d0       	movsd  (%rax,%rdx,8),%xmm0
    151e:	66 0f 28 c8          	movapd %xmm0,%xmm1
    1522:	f2 0f 59 4d b0       	mulsd  -0x50(%rbp),%xmm1
    1527:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    152b:	8b 55 80             	mov    -0x80(%rbp),%edx
    152e:	48 63 d2             	movslq %edx,%rdx
    1531:	f2 0f 10 04 d0       	movsd  (%rax,%rdx,8),%xmm0
    1536:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    153a:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    153e:	8b 55 80             	mov    -0x80(%rbp),%edx
    1541:	48 63 d2             	movslq %edx,%rdx
    1544:	f2 0f 11 04 d0       	movsd  %xmm0,(%rax,%rdx,8)
    1549:	83 45 80 01          	addl   $0x1,-0x80(%rbp)
    154d:	8b 45 80             	mov    -0x80(%rbp),%eax
    1550:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    1553:	7c ba                	jl     150f <main+0x2c6>
    1555:	e8 76 fb ff ff       	callq  10d0 <omp_get_wtime@plt>
    155a:	f2 0f 5c 45 b8       	subsd  -0x48(%rbp),%xmm0
    155f:	f2 0f 11 45 c0       	movsd  %xmm0,-0x40(%rbp)
    1564:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    1568:	66 48 0f 6e c0       	movq   %rax,%xmm0
    156d:	48 8d 3d b4 0a 00 00 	lea    0xab4(%rip),%rdi        # 2028 <_IO_stdin_used+0x28>
    1574:	b8 01 00 00 00       	mov    $0x1,%eax
    1579:	e8 72 fb ff ff       	callq  10f0 <printf@plt>
    157e:	48 89 dc             	mov    %rbx,%rsp
    1581:	b8 00 00 00 00       	mov    $0x0,%eax
    1586:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    158a:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
    1591:	00 00 
    1593:	74 05                	je     159a <main+0x351>
    1595:	e8 46 fb ff ff       	callq  10e0 <__stack_chk_fail@plt>
    159a:	48 8d 65 d8          	lea    -0x28(%rbp),%rsp
    159e:	5b                   	pop    %rbx
    159f:	41 5c                	pop    %r12
    15a1:	41 5d                	pop    %r13
    15a3:	41 5e                	pop    %r14
    15a5:	41 5f                	pop    %r15
    15a7:	5d                   	pop    %rbp
    15a8:	c3                   	retq   
    15a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000015b0 <__libc_csu_init>:
    15b0:	f3 0f 1e fa          	endbr64 
    15b4:	41 57                	push   %r15
    15b6:	4c 8d 3d ab 27 00 00 	lea    0x27ab(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    15bd:	41 56                	push   %r14
    15bf:	49 89 d6             	mov    %rdx,%r14
    15c2:	41 55                	push   %r13
    15c4:	49 89 f5             	mov    %rsi,%r13
    15c7:	41 54                	push   %r12
    15c9:	41 89 fc             	mov    %edi,%r12d
    15cc:	55                   	push   %rbp
    15cd:	48 8d 2d 9c 27 00 00 	lea    0x279c(%rip),%rbp        # 3d70 <__do_global_dtors_aux_fini_array_entry>
    15d4:	53                   	push   %rbx
    15d5:	4c 29 fd             	sub    %r15,%rbp
    15d8:	48 83 ec 08          	sub    $0x8,%rsp
    15dc:	e8 1f fa ff ff       	callq  1000 <_init>
    15e1:	48 c1 fd 03          	sar    $0x3,%rbp
    15e5:	74 1f                	je     1606 <__libc_csu_init+0x56>
    15e7:	31 db                	xor    %ebx,%ebx
    15e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    15f0:	4c 89 f2             	mov    %r14,%rdx
    15f3:	4c 89 ee             	mov    %r13,%rsi
    15f6:	44 89 e7             	mov    %r12d,%edi
    15f9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    15fd:	48 83 c3 01          	add    $0x1,%rbx
    1601:	48 39 dd             	cmp    %rbx,%rbp
    1604:	75 ea                	jne    15f0 <__libc_csu_init+0x40>
    1606:	48 83 c4 08          	add    $0x8,%rsp
    160a:	5b                   	pop    %rbx
    160b:	5d                   	pop    %rbp
    160c:	41 5c                	pop    %r12
    160e:	41 5d                	pop    %r13
    1610:	41 5e                	pop    %r14
    1612:	41 5f                	pop    %r15
    1614:	c3                   	retq   
    1615:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    161c:	00 00 00 00 

0000000000001620 <__libc_csu_fini>:
    1620:	f3 0f 1e fa          	endbr64 
    1624:	c3                   	retq   

Desensamblado de la sección .fini:

0000000000001628 <_fini>:
    1628:	f3 0f 1e fa          	endbr64 
    162c:	48 83 ec 08          	sub    $0x8,%rsp
    1630:	48 83 c4 08          	add    $0x8,%rsp
    1634:	c3                   	retq   
