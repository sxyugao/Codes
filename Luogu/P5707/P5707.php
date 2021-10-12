<?php
$input = trim(file_get_contents("php://stdin"));
list($s, $v) = explode(" ", $input);
$t = 8 * 60 + 24 * 60;
$t -= ceil($s / $v) + 10;
if ($t >= 24 * 60) $t -= 24 * 60;
$output = sprintf("%02d:%02d", floor($t / 60), $t % 60);
echo $output;
