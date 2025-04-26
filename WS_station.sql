-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Apr 26, 2025 at 09:12 PM
-- Server version: 8.0.37
-- PHP Version: 8.3.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
-- Table structure for table `WS_station`
--

CREATE TABLE `WS_station` (
  `id` int NOT NULL,
  `WS_nic` varchar(10) CHARACTER SET latin1 NOT NULL,
  `temperature` float NOT NULL,
  `humidity` float NOT NULL,
  `created_date` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `WS_station`
--

INSERT INTO `WS_station` (`id`, `WS_nic`, `temperature`, `humidity`, `created_date`) VALUES
(1, '38', 22.7, 49, '2025-04-26 07:12:27');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `WS_station`
--
ALTER TABLE `WS_station`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `WS_station`
--
ALTER TABLE `WS_station`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;