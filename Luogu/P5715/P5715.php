<?php
function swap(&$a, &$b) { $t = $a; $a = $b; $b = $t; }
$input = trim(file_get_contents("php://stdin"));
list($a, $b, $c) = explode(' ', $input);
if ($a > $b) swap($a, $b);
if ($a > $c) swap($a, $c);
if ($b > $c) swap($b, $c);
echo $a.' '.$b.' '.$c;