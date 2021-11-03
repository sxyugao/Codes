<?php
$x = trim(file_get_contents("php://stdin"));
if ($x > 5) print "Luogu";
else print "Local";