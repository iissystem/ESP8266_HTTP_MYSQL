<?php 

//require 'inc_conn.php';
require 'inc_conn.php';
//Both values must be same
define('PROJECT_API_KEY', 'pushdata_test_2025');

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	$api_key = escape_data($_POST["api_key"]);
        
	if($api_key == PROJECT_API_KEY) {
		$temperature = escape_data($_POST["temperature"]);
		$humidity = escape_data($_POST["humidity"]);
		$sql = "INSERT INTO WS_table(temperature,humidity,created_date) 
			VALUES('".$temperature."','".$humidity."','".date("Y-m-d H:i:s")."')";

		if($conn->query($sql) === FALSE)
			{ echo "Error: " . $sql . "<br>" . $conn->error; }

		echo "DONE. YOUR ID: ";
		echo $conn->insert_id;
	}
	else
	{
		echo "Wrong API Key";
	}
}

else
{
	echo "HTTP POST request not found";
}

function escape_data($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
