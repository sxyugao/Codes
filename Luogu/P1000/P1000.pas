
Var 
  n, m, p, q, i, j: longint;
  t: array[-2..22, -2..22] Of boolean;
  f: array[-1..20, -1..20] Of int64;
Begin
  read(n, m, p, q);
  fillchar(t, sizeof(t), true);
  t[p,q] := false;
  t[p-2,q-1] := false;
  t[p-2,q+1] := false;
  t[p+2,q-1] := false;
  t[p+2,q+1] := false;
  t[p-1,q-2] := false;
  t[p-1,q+2] := false;
  t[p+1,q-2] := false;
  t[p+1,q+2] := false;
  f[0,0] := 1;
  For i:=0 To n Do
    For j:=0 To m Do
      Begin
        If ((i = 0) And (j = 0)) Then continue;
        If t[i,j] Then f[i,j] := f[i-1,j]+f[i,j-1];
      End;
  write(f[n,m]);
End.
