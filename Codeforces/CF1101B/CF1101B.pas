
Var 
  s: string;
  i, j, len, L1, L2, R1, R2, ans: integer;
Begin
  readln(s);
  len := length(s);
  For i:=1 To len Do
    If s[i] = '[' Then
      Begin
        L1 := i;
        For j:=i + 1 To len Do
          If s[j] = ':' Then
            Begin
              L2 := j;
              break;
            End;
        break;
      End;
  For i:=len Downto 1 Do
    Begin
      If s[i] = ']' Then
        Begin
          R2 := i;
          For j:=i - 1 Downto 1 Do
            If s[j] = ':' Then
              Begin
                R1 := j;
                break;
              End;
          break;
        End;
    End;
  If (L1 = 0) Or (L2 = 0) Or (R1 = 0) Or (R2 = 0) Then
    Begin
      write(-1);
      halt(0);
    End;
  If (L1 = R2) Or (L2 = R1) Then
    Begin
      write(-1);
      halt(0);
    End;
  If L1 > R2 Then
    Begin
      write(-1);
      halt(0);
    End;
  If (R1 < L1) Or (L2 > R2) Then
    Begin
      write(-1);
      halt(0);
    End;
  ans := 4;
  For i:=L2 To R1 Do
    If s[i] = '|' Then inc(ans);
  write(ans);
End.
