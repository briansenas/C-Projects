
daxpyOs:     formato del fichero elf64-x86-64


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

00000000000010f0 <fputs@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 a5 2e 00 00 	bnd jmpq *0x2ea5(%rip)        # 3fa0 <fputs@GLIBC_2.2.5>
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

0000000000001130 <atoi@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 85 2e 00 00 	bnd jmpq *0x2e85(%rip)        # 3fc0 <atoi@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <exit@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 7d 2e 00 00 	bnd jmpq *0x2e7d(%rip)        # 3fc8 <exit@GLIBC_2.2.5>
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
    1168:	41 56                	push   %r14
    116a:	41 55                	push   %r13
    116c:	41 54                	push   %r12
    116e:	53                   	push   %rbx
    116f:	48 83 ec 20          	sub    $0x20,%rsp
    1173:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    117a:	00 00 
    117c:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    1180:	31 c0                	xor    %eax,%eax
    1182:	ff cf                	dec    %edi
    1184:	7f 1b                	jg     11a1 <main+0x41>
    1186:	48 8b 35 93 2e 00 00 	mov    0x2e93(%rip),%rsi        # 4020 <stderr@@GLIBC_2.2.5>
    118d:	48 8d 3d 70 0e 00 00 	lea    0xe70(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1194:	e8 57 ff ff ff       	callq  10f0 <fputs@plt>
    1199:	83 cf ff             	or     $0xffffffff,%edi
    119c:	e8 9f ff ff ff       	callq  1140 <exit@plt>
    11a1:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    11a5:	e8 86 ff ff ff       	callq  1130 <atoi@plt>
    11aa:	48 89 e6             	mov    %rsp,%rsi
    11ad:	89 c3                	mov    %eax,%ebx
    11af:	48 98                	cltq   
    11b1:	48 8d 04 c5 0f 00 00 	lea    0xf(,%rax,8),%rax
    11b8:	00 
    11b9:	48 89 c1             	mov    %rax,%rcx
    11bc:	48 89 c2             	mov    %rax,%rdx
    11bf:	48 81 e1 00 f0 ff ff 	and    $0xfffffffffffff000,%rcx
    11c6:	48 83 e2 f0          	and    $0xfffffffffffffff0,%rdx
    11ca:	48 29 ce             	sub    %rcx,%rsi
    11cd:	48 89 f1             	mov    %rsi,%rcx
    11d0:	48 39 cc             	cmp    %rcx,%rsp
    11d3:	74 12                	je     11e7 <main+0x87>
    11d5:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    11dc:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    11e3:	00 00 
    11e5:	eb e9                	jmp    11d0 <main+0x70>
    11e7:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    11ed:	48 29 d4             	sub    %rdx,%rsp
    11f0:	48 85 d2             	test   %rdx,%rdx
    11f3:	74 06                	je     11fb <main+0x9b>
    11f5:	48 83 4c 14 f8 00    	orq    $0x0,-0x8(%rsp,%rdx,1)
    11fb:	48 89 c2             	mov    %rax,%rdx
    11fe:	48 89 e1             	mov    %rsp,%rcx
    1201:	48 25 00 f0 ff ff    	and    $0xfffffffffffff000,%rax
    1207:	49 89 e4             	mov    %rsp,%r12
    120a:	48 29 c1             	sub    %rax,%rcx
    120d:	48 83 e2 f0          	and    $0xfffffffffffffff0,%rdx
    1211:	48 89 c8             	mov    %rcx,%rax
    1214:	48 39 c4             	cmp    %rax,%rsp
    1217:	74 12                	je     122b <main+0xcb>
    1219:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1220:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    1227:	00 00 
    1229:	eb e9                	jmp    1214 <main+0xb4>
    122b:	48 89 d0             	mov    %rdx,%rax
    122e:	25 ff 0f 00 00       	and    $0xfff,%eax
    1233:	48 29 c4             	sub    %rax,%rsp
    1236:	48 85 c0             	test   %rax,%rax
    1239:	74 06                	je     1241 <main+0xe1>
    123b:	48 83 4c 04 f8 00    	orq    $0x0,-0x8(%rsp,%rax,1)
    1241:	31 ff                	xor    %edi,%edi
    1243:	49 89 e5             	mov    %rsp,%r13
    1246:	45 31 f6             	xor    %r14d,%r14d
    1249:	e8 b2 fe ff ff       	callq  1100 <time@plt>
    124e:	48 89 c7             	mov    %rax,%rdi
    1251:	e8 ba fe ff ff       	callq  1110 <srand48@plt>
    1256:	83 fb 07             	cmp    $0x7,%ebx
    1259:	7f 24                	jg     127f <main+0x11f>
    125b:	31 c0                	xor    %eax,%eax
    125d:	39 c3                	cmp    %eax,%ebx
    125f:	7e 3d                	jle    129e <main+0x13e>
    1261:	f2 0f 2a c0          	cvtsi2sd %eax,%xmm0
    1265:	89 da                	mov    %ebx,%edx
    1267:	29 c2                	sub    %eax,%edx
    1269:	f2 41 0f 11 04 c4    	movsd  %xmm0,(%r12,%rax,8)
    126f:	f2 0f 2a c2          	cvtsi2sd %edx,%xmm0
    1273:	f2 41 0f 11 44 c5 00 	movsd  %xmm0,0x0(%r13,%rax,8)
    127a:	48 ff c0             	inc    %rax
    127d:	eb de                	jmp    125d <main+0xfd>
    127f:	e8 cc fe ff ff       	callq  1150 <drand48@plt>
    1284:	f2 43 0f 11 04 f4    	movsd  %xmm0,(%r12,%r14,8)
    128a:	e8 c1 fe ff ff       	callq  1150 <drand48@plt>
    128f:	f2 43 0f 11 44 f5 00 	movsd  %xmm0,0x0(%r13,%r14,8)
    1296:	49 ff c6             	inc    %r14
    1299:	44 39 f3             	cmp    %r14d,%ebx
    129c:	7f e1                	jg     127f <main+0x11f>
    129e:	e8 ad fe ff ff       	callq  1150 <drand48@plt>
    12a3:	f2 0f 11 45 c0       	movsd  %xmm0,-0x40(%rbp)
    12a8:	e8 23 fe ff ff       	callq  10d0 <omp_get_wtime@plt>
    12ad:	f2 0f 10 4d c0       	movsd  -0x40(%rbp),%xmm1
    12b2:	31 c0                	xor    %eax,%eax
    12b4:	f2 0f 11 45 c8       	movsd  %xmm0,-0x38(%rbp)
    12b9:	39 c3                	cmp    %eax,%ebx
    12bb:	7e 1c                	jle    12d9 <main+0x179>
    12bd:	f2 41 0f 10 44 c5 00 	movsd  0x0(%r13,%rax,8),%xmm0
    12c4:	f2 0f 59 c1          	mulsd  %xmm1,%xmm0
    12c8:	f2 41 0f 58 04 c4    	addsd  (%r12,%rax,8),%xmm0
    12ce:	f2 41 0f 11 04 c4    	movsd  %xmm0,(%r12,%rax,8)
    12d4:	48 ff c0             	inc    %rax
    12d7:	eb e0                	jmp    12b9 <main+0x159>
    12d9:	e8 f2 fd ff ff       	callq  10d0 <omp_get_wtime@plt>
    12de:	f2 0f 5c 45 c8       	subsd  -0x38(%rbp),%xmm0
    12e3:	48 8d 35 3a 0d 00 00 	lea    0xd3a(%rip),%rsi        # 2024 <_IO_stdin_used+0x24>
    12ea:	b0 01                	mov    $0x1,%al
    12ec:	bf 01 00 00 00       	mov    $0x1,%edi
    12f1:	e8 2a fe ff ff       	callq  1120 <__printf_chk@plt>
    12f6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    12fa:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1301:	00 00 
    1303:	74 05                	je     130a <main+0x1aa>
    1305:	e8 d6 fd ff ff       	callq  10e0 <__stack_chk_fail@plt>
    130a:	48 8d 65 e0          	lea    -0x20(%rbp),%rsp
    130e:	31 c0                	xor    %eax,%eax
    1310:	5b                   	pop    %rbx
    1311:	41 5c                	pop    %r12
    1313:	41 5d                	pop    %r13
    1315:	41 5e                	pop    %r14
    1317:	5d                   	pop    %rbp
    1318:	c3                   	retq   
    1319:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001320 <_start>:
    1320:	f3 0f 1e fa          	endbr64 
    1324:	31 ed                	xor    %ebp,%ebp
    1326:	49 89 d1             	mov    %rdx,%r9
    1329:	5e                   	pop    %rsi
    132a:	48 89 e2             	mov    %rsp,%rdx
    132d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1331:	50                   	push   %rax
    1332:	54                   	push   %rsp
    1333:	4c 8d 05 46 01 00 00 	lea    0x146(%rip),%r8        # 1480 <__libc_csu_fini>
    133a:	48 8d 0d cf 00 00 00 	lea    0xcf(%rip),%rcx        # 1410 <__libc_csu_init>
    1341:	48 8d 3d 18 fe ff ff 	lea    -0x1e8(%rip),%rdi        # 1160 <main>
    1348:	ff 15 92 2c 00 00    	callq  *0x2c92(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    134e:	f4                   	hlt    
    134f:	90                   	nop

0000000000001350 <deregister_tm_clones>:
    1350:	48 8d 3d b9 2c 00 00 	lea    0x2cb9(%rip),%rdi        # 4010 <__TMC_END__>
    1357:	48 8d 05 b2 2c 00 00 	lea    0x2cb2(%rip),%rax        # 4010 <__TMC_END__>
    135e:	48 39 f8             	cmp    %rdi,%rax
    1361:	74 15                	je     1378 <deregister_tm_clones+0x28>
    1363:	48 8b 05 6e 2c 00 00 	mov    0x2c6e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    136a:	48 85 c0             	test   %rax,%rax
    136d:	74 09                	je     1378 <deregister_tm_clones+0x28>
    136f:	ff e0                	jmpq   *%rax
    1371:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1378:	c3                   	retq   
    1379:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001380 <register_tm_clones>:
    1380:	48 8d 3d 89 2c 00 00 	lea    0x2c89(%rip),%rdi        # 4010 <__TMC_END__>
    1387:	48 8d 35 82 2c 00 00 	lea    0x2c82(%rip),%rsi        # 4010 <__TMC_END__>
    138e:	48 29 fe             	sub    %rdi,%rsi
    1391:	48 89 f0             	mov    %rsi,%rax
    1394:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1398:	48 c1 f8 03          	sar    $0x3,%rax
    139c:	48 01 c6             	add    %rax,%rsi
    139f:	48 d1 fe             	sar    %rsi
    13a2:	74 14                	je     13b8 <register_tm_clones+0x38>
    13a4:	48 8b 05 45 2c 00 00 	mov    0x2c45(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    13ab:	48 85 c0             	test   %rax,%rax
    13ae:	74 08                	je     13b8 <register_tm_clones+0x38>
    13b0:	ff e0                	jmpq   *%rax
    13b2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    13b8:	c3                   	retq   
    13b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000013c0 <__do_global_dtors_aux>:
    13c0:	f3 0f 1e fa          	endbr64 
    13c4:	80 3d 5d 2c 00 00 00 	cmpb   $0x0,0x2c5d(%rip)        # 4028 <completed.8060>
    13cb:	75 2b                	jne    13f8 <__do_global_dtors_aux+0x38>
    13cd:	55                   	push   %rbp
    13ce:	48 83 3d 22 2c 00 00 	cmpq   $0x0,0x2c22(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    13d5:	00 
    13d6:	48 89 e5             	mov    %rsp,%rbp
    13d9:	74 0c                	je     13e7 <__do_global_dtors_aux+0x27>
    13db:	48 8b 3d 26 2c 00 00 	mov    0x2c26(%rip),%rdi        # 4008 <__dso_handle>
    13e2:	e8 d9 fc ff ff       	callq  10c0 <__cxa_finalize@plt>
    13e7:	e8 64 ff ff ff       	callq  1350 <deregister_tm_clones>
    13ec:	c6 05 35 2c 00 00 01 	movb   $0x1,0x2c35(%rip)        # 4028 <completed.8060>
    13f3:	5d                   	pop    %rbp
    13f4:	c3                   	retq   
    13f5:	0f 1f 00             	nopl   (%rax)
    13f8:	c3                   	retq   
    13f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001400 <frame_dummy>:
    1400:	f3 0f 1e fa          	endbr64 
    1404:	e9 77 ff ff ff       	jmpq   1380 <register_tm_clones>
    1409:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001410 <__libc_csu_init>:
    1410:	f3 0f 1e fa          	endbr64 
    1414:	41 57                	push   %r15
    1416:	4c 8d 3d 4b 29 00 00 	lea    0x294b(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    141d:	41 56                	push   %r14
    141f:	49 89 d6             	mov    %rdx,%r14
    1422:	41 55                	push   %r13
    1424:	49 89 f5             	mov    %rsi,%r13
    1427:	41 54                	push   %r12
    1429:	41 89 fc             	mov    %edi,%r12d
    142c:	55                   	push   %rbp
    142d:	48 8d 2d 3c 29 00 00 	lea    0x293c(%rip),%rbp        # 3d70 <__do_global_dtors_aux_fini_array_entry>
    1434:	53                   	push   %rbx
    1435:	4c 29 fd             	sub    %r15,%rbp
    1438:	48 83 ec 08          	sub    $0x8,%rsp
    143c:	e8 bf fb ff ff       	callq  1000 <_init>
    1441:	48 c1 fd 03          	sar    $0x3,%rbp
    1445:	74 1f                	je     1466 <__libc_csu_init+0x56>
    1447:	31 db                	xor    %ebx,%ebx
    1449:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1450:	4c 89 f2             	mov    %r14,%rdx
    1453:	4c 89 ee             	mov    %r13,%rsi
    1456:	44 89 e7             	mov    %r12d,%edi
    1459:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    145d:	48 83 c3 01          	add    $0x1,%rbx
    1461:	48 39 dd             	cmp    %rbx,%rbp
    1464:	75 ea                	jne    1450 <__libc_csu_init+0x40>
    1466:	48 83 c4 08          	add    $0x8,%rsp
    146a:	5b                   	pop    %rbx
    146b:	5d                   	pop    %rbp
    146c:	41 5c                	pop    %r12
    146e:	41 5d                	pop    %r13
    1470:	41 5e                	pop    %r14
    1472:	41 5f                	pop    %r15
    1474:	c3                   	retq   
    1475:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    147c:	00 00 00 00 

0000000000001480 <__libc_csu_fini>:
    1480:	f3 0f 1e fa          	endbr64 
    1484:	c3                   	retq   

Desensamblado de la sección .fini:

0000000000001488 <_fini>:
    1488:	f3 0f 1e fa          	endbr64 
    148c:	48 83 ec 08          	sub    $0x8,%rsp
    1490:	48 83 c4 08          	add    $0x8,%rsp
    1494:	c3                   	retq   
