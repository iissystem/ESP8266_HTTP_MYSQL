<?php
//mysqli connection will began here
$conn = mysqli_connect('localhost', 'USER_NAME', 'PASSWORD', 'DATABASE_TABLE');  
date_default_timezone_set("Europe/Rome");
if (! $conn) {  
         die("Connection failed" . mysqli_connect_error());  
}
?>
