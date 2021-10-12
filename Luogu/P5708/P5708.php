<?php
$input = trim(file_get_contents("php://stdin"));
list($a, $b, $c) = explode(" ", $input);
$p = ($a + $b + $c) / 2;
$output = sprintf("%.1lf", sqrt($p * ($p - $a) * ($p - $b) * ($p - $c)), 1);
echo $output;