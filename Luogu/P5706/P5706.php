<?php
$T = trim(file_get_contents("php://stdin"));
if ($T == 1) echo "I love Luogu!";
if ($T == 2) echo 6, " ", 4;
if ($T == 3) {
  $n = 14; $x = 4;
  $cnt = floor($n / $x);
  echo $cnt, "\n", $cnt * $x, "\n", $n % $cnt;
}
if ($T == 4) echo round(500 / 3, 3);
if ($T == 5) echo (260 + 220) / (12 + 20);
if ($T == 6) echo round(sqrt(6 * 6 + 9 * 9), 4);
if ($T == 7) echo "110\n90\n0";
if ($T == 8) {
  $p = 3.141593; $r = 5;
  echo substr(2 * $p * $r, 0, 7), "\n";
  echo substr($p * pow($r, 2), 0, 7), "\n";
  echo round(4 / 3 * $p * pow($r, 3), 3);
}
if ($T == 9) {
  $x = 1;
  for ($i = 0; $i < 3; $i++) $x= ($x + 1) * 2;
  echo $x;
}
if ($T == 10) echo 9;
if ($T == 11) echo round(100 / 3, 4);
if ($T == 12) echo ord('M') - ord('A') + 1, "\n", chr(ord('A') + 17);
if ($T == 13) {
  $p = 3.141593; $r1 = 4; $r2 = 10;
  echo floor(pow(4 / 3 * $p * pow($r1, 3) + 4 / 3 * $p * pow($r2, 3), 1 / 3));
}
if ($T == 14) echo 50;

