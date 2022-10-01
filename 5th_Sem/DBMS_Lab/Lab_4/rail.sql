-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 22, 2022 at 10:49 AM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `railway`
--

-- --------------------------------------------------------

--
-- Table structure for table `compartment`
--

CREATE TABLE `compartment` (
  `compartment_no` varchar(10) NOT NULL,
  `compartment_type` varchar(10) DEFAULT NULL,
  `capacity` int(11) DEFAULT NULL,
  `availability` int(11) DEFAULT NULL,
  `train_number` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `compartment`
--

INSERT INTO `compartment` (`compartment_no`, `compartment_type`, `capacity`, `availability`, `train_number`) VALUES
('F01', 'I Class', 16, 0, 25260),
('F01', 'I Class', 16, 0, 25261),
('F01', 'I Class', 16, 4, 58450),
('F01', 'I Class', 16, 5, 58451),
('F01', 'I Class', 16, 15, 62620),
('F01', 'I Class', 16, 6, 62621),
('F02', 'I Class', 16, 0, 62620),
('G01', 'III Class', 60, 33, 25261),
('G01', 'III Class', 60, 2, 58450),
('G01', 'III Class', 60, 40, 58451),
('G01', 'III Class', 60, 10, 62621),
('G02', 'III Class', 60, 45, 25261),
('G02', 'III Class', 60, 12, 62621),
('S01', 'II Class', 30, 15, 25260),
('S01', 'II Class', 30, 15, 25261),
('S01', 'II Class', 30, 5, 58450),
('S01', 'II Class', 30, 4, 62621),
('S02', 'II Class', 30, 17, 25260),
('S02', 'II Class', 30, 3, 58450),
('S02', 'II Class', 30, 6, 62621);

-- --------------------------------------------------------

--
-- Table structure for table `fare`
--

CREATE TABLE `fare` (
  `train_type` varchar(20) NOT NULL,
  `compartment_type` varchar(10) NOT NULL,
  `fare_per_km` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fare`
--

INSERT INTO `fare` (`train_type`, `compartment_type`, `fare_per_km`) VALUES
('Fast', 'I Class', 3),
('Mail', 'I Class', 2),
('Superfast', 'I Class', 3),
('Fast', 'II Class', 2),
('Mail', 'II Class', 1),
('Superfast', 'II Class', 2),
('Fast', 'III Class', 1),
('Mail', 'III Class', 1),
('Superfast', 'III Class', 1);

-- --------------------------------------------------------

--
-- Table structure for table `payment_info`
--

CREATE TABLE `payment_info` (
  `transaction_no` int(11) NOT NULL,
  `bank` varchar(20) DEFAULT NULL,
  `card_no` varchar(20) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL,
  `pnr` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `payment_info`
--

INSERT INTO `payment_info` (`transaction_no`, `bank`, `card_no`, `price`, `pnr`) VALUES
(146445, 'HDFC', '1.23433E+15', NULL, 'PNR006'),
(243535, 'UNION BANK', '2.43647E+15', NULL, 'PNR012'),
(342344, 'IOB', '5.62357E+15', NULL, 'PNR001'),
(354364, 'CANARA BANK', '5.76879E+15', NULL, 'PNR014'),
(531343, 'SBI', '8.95327E+15', NULL, 'PNR004'),
(576768, 'ICICI', '7.56356E+15', NULL, 'PNR007'),
(676756, 'CANARA BANK', '7.36756E+15', NULL, 'PNR002'),
(746745, 'KOTAK', '2.54564E+15', NULL, 'PNR008'),
(758900, 'UNION BANK', '2.43266E+15', NULL, 'PNR015'),
(867546, 'UNION BANK', '4.65769E+15', NULL, 'PNR010'),
(867547, 'SBI', '7.46635E+15', NULL, 'PNR011'),
(978098, 'INDIAN BANK', '9.88733E+15', NULL, 'PNR005'),
(978776, 'UNION BANK', '1I54978597435874', NULL, 'PNR003');

-- --------------------------------------------------------

--
-- Table structure for table `route_info`
--

CREATE TABLE `route_info` (
  `from_station_no` int(11) NOT NULL,
  `to_station_no` int(11) NOT NULL,
  `from_station_name` varchar(20) DEFAULT NULL,
  `to_station_name` varchar(20) DEFAULT NULL,
  `distance` int(11) DEFAULT NULL,
  `train_no` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `route_info`
--

INSERT INTO `route_info` (`from_station_no`, `to_station_no`, `from_station_name`, `to_station_name`, `distance`, `train_no`) VALUES
(1, 2, 'Mangaluru', 'Kannur', 131, 25260),
(1, 3, 'Mangaluru', 'Palakkad', 351, 25260),
(1, 4, 'Mangaluru', 'Chennai', 481, 25260),
(2, 3, 'Kannur ', 'Palakkad', 220, 25260),
(2, 4, 'Kannur ', 'Chennai', 350, 25260),
(4, 4, 'Palakkad', 'Chennai', 130, 25260),
(1, 2, 'Chennai', 'Palakkad', 130, 25261),
(1, 3, 'Chennai', 'Kannur', 350, 25261),
(1, 4, 'Chennai', 'Mangaluru', 481, 25261),
(2, 3, 'Palakkad', 'Kannur', 220, 25261),
(2, 4, 'Palakkad', 'Mangaluru', 351, 25261),
(3, 4, 'Kannur ', 'Mangaluru', 131, 25261),
(1, 2, 'Mangaluru', 'Subramanya', 195, 58450),
(1, 3, 'Mangaluru', 'Mysore', 365, 58450),
(1, 4, 'Mangaluru', 'Bengaluru', 504, 58450),
(2, 3, 'Subramanya', 'Mysore', 170, 58450),
(2, 4, 'Subramanya', 'Bengaluru', 309, 58450),
(3, 4, 'Mysore', 'Bengaluru', 139, 58450),
(1, 2, 'Bengaluru', 'Mysore', 139, 58451),
(1, 3, 'Bengaluru', 'Subramanya', 309, 58451),
(1, 4, 'Bengaluru', 'Mangaluru', 503, 58451),
(2, 3, 'Mysore', 'Subramanya', 170, 58451),
(2, 4, 'Mysore', 'Mangaluru', 364, 58451),
(3, 4, 'Subramanya', 'Mangaluru', 194, 58451),
(1, 2, 'Chennai', 'Sholingur', 90, 62620),
(1, 3, 'Chennai', 'Katpadi', 129, 62620),
(1, 4, 'Chennai', 'Bangarpet', 290, 62620),
(1, 5, 'Chennai', 'Bengaluru', 361, 62620),
(2, 3, 'Sholingur', 'Katpadi', 39, 62620),
(2, 4, 'Sholingur', 'Bangarpet', 200, 62620),
(2, 5, 'Sholingur', 'Chennai', 271, 62620),
(3, 4, 'Katpadi', 'Bangarpet', 161, 62620),
(3, 5, 'Katpadi', 'Chennai', 232, 62620),
(4, 5, 'Bangarpet', 'Bengaluru', 71, 62620),
(1, 2, 'Bengaluru', 'Bangarpet', 71, 62621),
(1, 3, 'Bengaluru', 'Katpadi', 232, 62621),
(1, 4, 'Bengaluru', 'Sholigur', 272, 62621),
(1, 5, 'Bengaluru', 'Chennai', 362, 62621),
(2, 3, 'Bangarpet', 'Katpadi', 161, 62621),
(2, 4, 'Bangarpet', 'Sholigur', 201, 62621),
(2, 5, 'Bangarpet', 'Chennai', 291, 62621),
(3, 4, 'Katpadi', 'Sholigur', 40, 62621),
(3, 5, 'Katpadi', 'Chennai', 130, 62621),
(4, 5, 'Sholingur', 'Chennai', 90, 62621);

-- --------------------------------------------------------

--
-- Table structure for table `ticket`
--

CREATE TABLE `ticket` (
  `pnr` varchar(10) NOT NULL,
  `train_no` int(11) DEFAULT NULL,
  `travel_date` date DEFAULT NULL,
  `departure` varchar(30) DEFAULT NULL,
  `arrival` varchar(30) DEFAULT NULL,
  `departure_time` time DEFAULT NULL,
  `arrival_time` time DEFAULT NULL,
  `passenger_id` varchar(20) DEFAULT NULL,
  `train_type` varchar(20) DEFAULT NULL,
  `compartment_type` varchar(10) DEFAULT NULL,
  `compartment_no` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `ticket`
--

INSERT INTO `ticket` (`pnr`, `train_no`, `travel_date`, `departure`, `arrival`, `departure_time`, `arrival_time`, `passenger_id`, `train_type`, `compartment_type`, `compartment_no`) VALUES
('PNR001', 62621, '2022-08-07', 'Bengaluru', 'Chennai', '16:00:00', '20:30:00', 'ADM_001', 'Superfast', 'I Class', 'F01'),
('PNR002', 62620, '2022-08-14', 'Chennai', 'Bengaluru', '08:00:00', '12:25:00', 'ADM_001', 'Superfast', 'I Class', 'F02'),
('PNR003', 25261, '2022-08-01', 'Chennai', 'Mangaluru', '18:00:00', '07:30:00', 'ADM_003', 'Mail', 'III Class', 'G02'),
('PNR004', 25260, '2022-08-15', 'Mangaluru', 'Chennai', '19:15:00', '08:00:00', 'ADM_003', 'Mail', 'II Class', 'S02'),
('PNR005', 58451, '2022-08-03', 'Bengaluru', 'Mangaluru', '06:00:00', '14:00:00', 'USR_002', 'Fast', 'III Class', 'G01'),
('PNR006', 58450, '2033-08-04', 'Mangaluru', 'Bengaluru', '08:00:00', '10:15:00', 'USR_002', 'Fast', 'II Class', 'S01'),
('PNR007', 62621, '2022-08-07', 'Bangarpet', 'Chennai', '18:00:00', '20:30:00', 'ADM_002', 'Superfast', 'II Class', 'S01'),
('PNR008', 62620, '2022-08-02', 'Chennai', 'Bangarpet', '08:00:00', '09:00:00', 'ADM_002', 'Superfast', 'I Class', 'F01'),
('PNR010', 25260, '2022-08-19', 'Mangaluru', 'Kannur', '19:15:00', '23:15:00', 'USR_007', 'Mail', 'II Class', 'S01'),
('PNR011', 62621, '2022-08-22', 'Katapadi', 'Chennai', '19:00:00', '20:30:00', 'USR_008', 'Superfast', 'I Class', 'F01'),
('PNR012', 58451, '2022-08-11', 'Subramanya', 'Mangaluru', '11:00:00', '14:00:00', 'USR_009', 'Fast', 'I Class', 'F01'),
('PNR014', 25260, '2022-08-17', 'Kannur', 'Palakkad', '23:15:00', '04:30:00', 'USR_010', 'Mail', 'II Class', 'S01'),
('PNR015', 25260, '2022-08-05', 'Palakkad', 'Chennai', '04:30:00', '08:00:00', 'USR_012', 'Mail', 'II Class', 'S01');

-- --------------------------------------------------------

--
-- Table structure for table `ticket_passenger`
--

CREATE TABLE `ticket_passenger` (
  `seat_no` varchar(10) NOT NULL,
  `name` varchar(30) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `pnr` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `ticket_passenger`
--

INSERT INTO `ticket_passenger` (`seat_no`, `name`, `age`, `pnr`) VALUES
('F01-3', 'Saideepak Reddy', 27, 'PNR001'),
('F01-4', 'Sheela Reddy', 25, 'PNR001'),
('F02-11', 'SaiDeepak Reddy', 27, 'PNR002'),
('F02-12', 'Sheela Reddy', 25, 'PNR002'),
('G01-50', 'Anwar Hussein', 32, 'PNR003'),
('G01-51', 'Karishma Husein', 12, 'PNR003'),
('G02-31', 'Anwar Hussein', 32, 'PNR004'),
('G02-32', 'Karishma Husein', 12, 'PNR004'),
('S01-10', 'Hema Ullal', 27, 'PNR005'),
('S01-11', 'Hima Ullal', 28, 'PNR005'),
('S01-12', 'Asha Ullal', 21, 'PNR005'),
('S01-9', 'Ajit Ullal', 31, 'PNR005'),
('S01-35', 'Smriti Irani', 40, 'PNR006'),
('S01-14', 'Christon D Souza', 27, 'PNR007'),
('F01-8', 'Christon D Souza', 27, 'PNR008'),
('S01-25', 'Samanta Prabhu', 21, 'PNR010'),
('S01-26', 'Rakshita Prabhu', 21, 'PNR010'),
('F01-7', 'Sheela Seth', 33, 'PNR011'),
('F01-13', 'Ramya R', 45, 'PNR012'),
('S01-2', 'Shradha Nayar', 20, 'PNR014'),
('S01-29', 'Khushi Jha', 18, 'PNR015');

-- --------------------------------------------------------

--
-- Table structure for table `train`
--

CREATE TABLE `train` (
  `train_no` int(11) NOT NULL,
  `train_name` varchar(20) DEFAULT NULL,
  `train_type` varchar(10) DEFAULT NULL,
  `source` varchar(20) DEFAULT NULL,
  `destination` varchar(30) DEFAULT NULL,
  `availability` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `train`
--

INSERT INTO `train` (`train_no`, `train_name`, `train_type`, `source`, `destination`, `availability`) VALUES
(25260, 'Chennai Mail', 'Mail', 'Mangaluru', 'Chennai', 'Yes'),
(25261, 'Managaluru Mail', 'Mail', 'Chennai ', 'Mangaluru', 'Yes'),
(58450, 'MAN-BEN Express', 'Fast', 'Mangaluru', 'Bengaluru', 'yes'),
(58451, 'BEN-MAN Express', 'Fast', 'Bengaluru', 'Mangaluru', 'yes'),
(62620, 'CHE-BEN Shatabdi', 'Superfast', 'Chennai ', 'Bengaluru', 'No'),
(62621, 'BEN-CHE Shatabdi', 'Superfast', 'Bengaluru', 'Chennai', 'yes');

-- --------------------------------------------------------

--
-- Table structure for table `train_user`
--

CREATE TABLE `train_user` (
  `user_id` varchar(20) NOT NULL,
  `user_type` varchar(10) DEFAULT NULL,
  `firstname` varchar(50) DEFAULT NULL,
  `lastname` varchar(50) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `dob` date DEFAULT NULL,
  `pincode` varchar(20) DEFAULT NULL,
  `street_number` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `train_user`
--

INSERT INTO `train_user` (`user_id`, `user_type`, `firstname`, `lastname`, `age`, `dob`, `pincode`, `street_number`) VALUES
('ADM_001', 'ADMIN', 'Narendra ', 'Modi', NULL, '1989-04-14', '600047', 'Old Jail Road'),
('ADM_002', 'ADMIN', 'Droupadi', 'Murmu', NULL, '1990-04-14', '640012', 'High Street'),
('ADM_003', 'ADMIN', 'Manmohan ', 'Singh', NULL, '1991-04-08', '575003', 'Pumpwell Road'),
('USR_001', 'PSGR', '  Ajit', 'Ullal', NULL, '1971-01-01', '560001', '10, Janpath'),
('USR_002', 'PSGR', 'Muhammed ', 'Ali', NULL, '2000-10-09', '560003', '10, Downing'),
('USR_003', 'PSGR', 'Sai Deepak', 'Reddy', NULL, '1996-12-12', '600001', '14, Kailsh Marg'),
('USR_004', 'PSGR', 'Rudra', 'Agarwal', NULL, '1996-12-13', '600042', '5, Lohia Garden'),
('USR_005', 'PSGR', 'Rahul', 'Khanna', NULL, '1997-12-14', '600067', '1, Pink Street'),
('USR_006', 'PSGR', 'Nirmala', 'Seturaman', NULL, '1998-12-15', '560105', '3, Blue Avenue'),
('USR_007', 'PSGR', 'Smriti', 'Irani', NULL, '1999-12-16', '575014', '4, Banyan Avenie'),
('USR_008', 'PSGR', 'Ajit', 'Sethi', NULL, '1966-04-14', '575001', '6, Poes Garden'),
('USR_009', 'PSGR', 'Arjun', 'Allu', NULL, '1967-04-08', '575020', '7, Dhamaka street'),
('USR_010', 'PSGR', 'Samanta', 'Prabhu', NULL, '1968-04-14', '600042', '8, Clone Colony'),
('USR_011', 'PSGR', 'Kiran ', 'Bedi', NULL, '1969-04-14', '560003', '56, Brigade Road'),
('USR_012', 'PSGR', 'Rahul ', 'Gandhi', NULL, '1970-04-08', '475001', 'Mirza road'),
('USR_013', 'PSGR', 'Rashkit ', 'Shetty', NULL, '1971-04-14', '560009', 'JC Road'),
('USR_014', 'PSGR', 'Rishi', 'Sunak', NULL, '1972-04-14', '600034', 'Anna Sali'),
('USR_015', 'PSGR', 'Vedavalli', 'Srinath', NULL, '1973-04-14', '560054', 'Church Street, Bangalore'),
('USR_016', 'PSGR', 'Subbu', 'Saravana', NULL, '1974-04-14', '600043', 'American Street'),
('USR_017', 'PSGR', 'Sheela', 'Dixit', NULL, '1975-04-08', '560048', 'Kasturba Road'),
('USR_018', 'PSGR', 'Margaret', 'Alva', NULL, '1976-04-14', '560008', 'New BEL Road'),
('USR_019', 'PSGR', 'Arun', 'Kumar', NULL, '1977-04-14', '600046', 'Mint Street'),
('USR_020', 'PSGR', 'Anshu', 'Bhardwaj', NULL, '1978-04-14', '575001', 'KSR Road'),
('USR_021', 'PSGR', 'Suma', 'Sampat', NULL, '1979-04-08', '560012', 'Old Airport Road, Bangalore'),
('USR_022', 'PSGR', 'Srihari', 'Udupa', NULL, '1980-04-14', '560015', 'Suranjan Das Road'),
('USR_023', 'PSGR', 'Satish', 'Kotian', NULL, '1981-04-14', '600044', 'T Nagar'),
('USR_024', 'PSGR', 'Shradha', 'Nayar', NULL, '1982-04-08', '560006', 'M G Road, Bangalore'),
('USR_025', 'PSGR', 'Manisha', 'Solanki', NULL, '1983-04-08', '575030', 'M G Road'),
('USR_026', 'PSGR', 'Bharti', 'Devgan', NULL, '1984-04-14', '560059', 'NAL Wind Tunnel Road'),
('USR_027', 'PSGR', 'Roopa', 'Ram', NULL, '1985-04-14', '575023', 'Bunder Road'),
('USR_028', 'PSGR', 'Pallavi', 'Ram', NULL, '1986-04-08', '560044', 'Lavelle Road'),
('USR_029', 'PSGR', 'Ravi', 'Naik', NULL, '1987-04-14', '600045', 'Thiru V ka Salai'),
('USR_030', 'PSGR', 'Virat', 'Murthy', NULL, '1988-04-14', '575011', 'Bejai New Road');

-- --------------------------------------------------------

--
-- Table structure for table `user_phone`
--

CREATE TABLE `user_phone` (
  `user_id` varchar(20) NOT NULL,
  `phone_no` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_phone`
--

INSERT INTO `user_phone` (`user_id`, `phone_no`) VALUES
('ADM_001', '9845012345'),
('ADM_001', '9900123456'),
('ADM_002', '9845012345'),
('ADM_002', '9900123456'),
('ADM_003', '9845012345'),
('ADM_003', '9900123456'),
('USR_001', '9845012345'),
('USR_001', '9900123456'),
('USR_002', '9845012345'),
('USR_002', '9900123456'),
('USR_003', '9845012345'),
('USR_003', '9900123456'),
('USR_004', '9845012345'),
('USR_004', '9900123456'),
('USR_005', '9845012345'),
('USR_005', '9900123456'),
('USR_006', '9845012345'),
('USR_006', '9900123456'),
('USR_007', '9845012345'),
('USR_007', '9900123456'),
('USR_008', '9845012345'),
('USR_008', '9900123456'),
('USR_009', '9845012345'),
('USR_009', '9900123456'),
('USR_010', '9845012345'),
('USR_010', '9900123456'),
('USR_011', '9845012345'),
('USR_011', '9900123456'),
('USR_012', '9845012345'),
('USR_012', '9900123456'),
('USR_013', '9845012345'),
('USR_013', '9900123456'),
('USR_014', '9845012345'),
('USR_014', '9900123456'),
('USR_015', '9845012345'),
('USR_015', '9900123456'),
('USR_016', '9845012345'),
('USR_016', '9900123456'),
('USR_017', '9845012345'),
('USR_017', '9900123456'),
('USR_018', '9845012345'),
('USR_018', '9900123456'),
('USR_019', '9845012345'),
('USR_019', '9900123456'),
('USR_020', '9845012345'),
('USR_020', '9900123456'),
('USR_021', '9845012345'),
('USR_021', '9900123456'),
('USR_022', '9845012345'),
('USR_022', '9900123456'),
('USR_023', '9845012345'),
('USR_023', '9900123456'),
('USR_024', '9845012345'),
('USR_024', '9900123456'),
('USR_025', '9845012345'),
('USR_025', '9900123456'),
('USR_026', '9845012345'),
('USR_026', '9900123456'),
('USR_027', '9845012345'),
('USR_027', '9900123456'),
('USR_028', '9845012345'),
('USR_028', '9900123456'),
('USR_029', '9845012345'),
('USR_029', '9900123456'),
('USR_030', '9845012345'),
('USR_030', '9900123456');

-- --------------------------------------------------------

--
-- Table structure for table `user_train`
--

CREATE TABLE `user_train` (
  `user_id` varchar(10) NOT NULL,
  `train_id` int(11) NOT NULL,
  `date_time_stamp` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_train`
--

INSERT INTO `user_train` (`user_id`, `train_id`, `date_time_stamp`) VALUES
('ADM_001', 25261, '2022-07-22 08:08:48'),
('ADM_001', 25261, '2022-07-22 08:08:54'),
('ADM_001', 25261, '2022-07-22 08:09:09'),
('ADM_001', 58450, '2022-07-22 08:09:00'),
('ADM_001', 58451, '2022-07-22 08:09:03'),
('ADM_001', 58451, '2022-07-22 08:09:12'),
('ADM_001', 62620, '2022-07-22 08:08:51'),
('ADM_001', 62620, '2022-07-22 08:08:57'),
('ADM_001', 62621, '2022-07-22 08:09:06'),
('ADM_002', 25261, '2022-07-22 08:09:10'),
('ADM_002', 58450, '2022-07-22 08:08:52'),
('ADM_002', 58450, '2022-07-22 08:08:58'),
('ADM_002', 58450, '2022-07-22 08:09:01'),
('ADM_002', 58451, '2022-07-22 08:09:04'),
('ADM_002', 58451, '2022-07-22 08:09:07'),
('ADM_002', 62620, '2022-07-22 08:08:46'),
('ADM_002', 62620, '2022-07-22 08:09:13'),
('ADM_002', 62621, '2022-07-22 08:08:49'),
('ADM_002', 62621, '2022-07-22 08:08:55'),
('ADM_003', 25260, '2022-07-22 08:09:38'),
('ADM_003', 25261, '2022-07-22 08:08:53'),
('ADM_003', 25261, '2022-07-22 08:08:59'),
('ADM_003', 58450, '2022-07-22 08:08:47'),
('ADM_003', 58450, '2022-07-22 08:09:02'),
('ADM_003', 58450, '2022-07-22 08:09:14'),
('ADM_003', 58451, '2022-07-22 08:08:50'),
('ADM_003', 58451, '2022-07-22 08:08:56'),
('ADM_003', 58451, '2022-07-22 08:09:05'),
('ADM_003', 62620, '2022-07-22 08:09:08'),
('ADM_003', 62621, '2022-07-22 08:09:11'),
('USR_001', 58451, '2022-07-22 08:09:15'),
('USR_002', 58451, '2022-07-22 08:09:16'),
('USR_003', 58450, '2022-07-22 08:10:01'),
('USR_003', 58450, '2022-07-22 08:10:04'),
('USR_003', 58451, '2022-07-22 08:09:18'),
('USR_003', 62620, '2022-07-22 08:10:03'),
('USR_003', 62620, '2022-07-22 08:10:11'),
('USR_003', 62621, '2022-07-22 08:09:17'),
('USR_004', 25261, '2022-07-22 08:10:15'),
('USR_004', 58450, '2022-07-22 08:09:20'),
('USR_004', 62620, '2022-07-22 08:09:19'),
('USR_004', 62620, '2022-07-22 08:10:18'),
('USR_005', 25261, '2022-07-22 08:10:20'),
('USR_005', 58451, '2022-07-22 08:09:21'),
('USR_005', 62620, '2022-07-22 08:09:22'),
('USR_005', 62620, '2022-07-22 08:10:24'),
('USR_005', 62621, '2022-07-22 08:10:22'),
('USR_006', 58450, '2022-07-22 08:09:23'),
('USR_006', 58451, '2022-07-22 08:09:24'),
('USR_006', 62621, '2022-07-22 08:10:16'),
('USR_007', 25260, '2022-07-22 08:08:45'),
('USR_007', 58451, '2022-07-22 08:09:25'),
('USR_007', 62621, '2022-07-22 08:09:26'),
('USR_007', 62621, '2022-07-22 08:10:07'),
('USR_008', 58451, '2022-07-22 08:09:27'),
('USR_008', 62621, '2022-07-22 08:09:28'),
('USR_008', 62621, '2022-07-22 08:10:09'),
('USR_009', 25261, '2022-07-22 08:10:21'),
('USR_009', 58451, '2022-07-22 08:09:29'),
('USR_009', 62620, '2022-07-22 08:09:30'),
('USR_010', 58450, '2022-07-22 08:09:31'),
('USR_010', 58451, '2022-07-22 08:09:32'),
('USR_011', 58451, '2022-07-22 08:09:33'),
('USR_011', 62621, '2022-07-22 08:09:34'),
('USR_012', 58450, '2022-07-22 08:09:36'),
('USR_012', 58451, '2022-07-22 08:09:35'),
('USR_012', 58451, '2022-07-22 08:10:02'),
('USR_013', 58451, '2022-07-22 08:09:37'),
('USR_013', 58451, '2022-07-22 08:10:05'),
('USR_013', 58451, '2022-07-22 08:10:06'),
('USR_014', 58450, '2022-07-22 08:09:39'),
('USR_014', 58451, '2022-07-22 08:09:40'),
('USR_014', 58451, '2022-07-22 08:10:08'),
('USR_015', 25261, '2022-07-22 08:10:26'),
('USR_015', 58451, '2022-07-22 08:09:41'),
('USR_015', 58451, '2022-07-22 08:10:10'),
('USR_015', 62621, '2022-07-22 08:09:42'),
('USR_016', 58451, '2022-07-22 08:09:43'),
('USR_016', 62621, '2022-07-22 08:09:44'),
('USR_017', 58451, '2022-07-22 08:09:45'),
('USR_017', 62620, '2022-07-22 08:09:46'),
('USR_018', 58450, '2022-07-22 08:09:47'),
('USR_018', 58451, '2022-07-22 08:09:48'),
('USR_019', 58450, '2022-07-22 08:10:25'),
('USR_019', 58451, '2022-07-22 08:09:49'),
('USR_020', 58450, '2022-07-22 08:10:27'),
('USR_020', 58451, '2022-07-22 08:09:50'),
('USR_021', 58450, '2022-07-22 08:10:12'),
('USR_021', 62621, '2022-07-22 08:09:51'),
('USR_022', 58450, '2022-07-22 08:10:14'),
('USR_022', 58451, '2022-07-22 08:09:52'),
('USR_022', 58451, '2022-07-22 08:10:23'),
('USR_023', 58450, '2022-07-22 08:10:19'),
('USR_023', 62621, '2022-07-22 08:09:53'),
('USR_024', 58451, '2022-07-22 08:09:54'),
('USR_025', 62620, '2022-07-22 08:09:55'),
('USR_026', 58450, '2022-07-22 08:09:56'),
('USR_026', 58451, '2022-07-22 08:10:13'),
('USR_027', 58451, '2022-07-22 08:09:57'),
('USR_027', 58451, '2022-07-22 08:10:17'),
('USR_028', 58451, '2022-07-22 08:09:58'),
('USR_029', 62621, '2022-07-22 08:09:59'),
('USR_030', 58451, '2022-07-22 08:10:00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `compartment`
--
ALTER TABLE `compartment`
  ADD PRIMARY KEY (`compartment_no`,`train_number`),
  ADD KEY `train_number` (`train_number`);

--
-- Indexes for table `fare`
--
ALTER TABLE `fare`
  ADD PRIMARY KEY (`compartment_type`,`train_type`);

--
-- Indexes for table `payment_info`
--
ALTER TABLE `payment_info`
  ADD PRIMARY KEY (`transaction_no`),
  ADD KEY `pnr` (`pnr`);

--
-- Indexes for table `route_info`
--
ALTER TABLE `route_info`
  ADD PRIMARY KEY (`train_no`,`from_station_no`,`to_station_no`);

--
-- Indexes for table `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`pnr`),
  ADD KEY `train_no` (`train_no`),
  ADD KEY `passenger_id` (`passenger_id`),
  ADD KEY `compartment_no` (`compartment_no`);

--
-- Indexes for table `ticket_passenger`
--
ALTER TABLE `ticket_passenger`
  ADD PRIMARY KEY (`pnr`,`seat_no`);

--
-- Indexes for table `train`
--
ALTER TABLE `train`
  ADD PRIMARY KEY (`train_no`);

--
-- Indexes for table `train_user`
--
ALTER TABLE `train_user`
  ADD PRIMARY KEY (`user_id`);

--
-- Indexes for table `user_phone`
--
ALTER TABLE `user_phone`
  ADD PRIMARY KEY (`user_id`,`phone_no`);

--
-- Indexes for table `user_train`
--
ALTER TABLE `user_train`
  ADD PRIMARY KEY (`user_id`,`train_id`,`date_time_stamp`),
  ADD KEY `train_id` (`train_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `compartment`
--
ALTER TABLE `compartment`
  ADD CONSTRAINT `compartment_ibfk_1` FOREIGN KEY (`train_number`) REFERENCES `train` (`train_no`);

--
-- Constraints for table `payment_info`
--
ALTER TABLE `payment_info`
  ADD CONSTRAINT `payment_info_ibfk_1` FOREIGN KEY (`pnr`) REFERENCES `ticket` (`pnr`);

--
-- Constraints for table `route_info`
--
ALTER TABLE `route_info`
  ADD CONSTRAINT `route_info_ibfk_1` FOREIGN KEY (`train_no`) REFERENCES `train` (`train_no`);

--
-- Constraints for table `ticket`
--
ALTER TABLE `ticket`
  ADD CONSTRAINT `ticket_ibfk_1` FOREIGN KEY (`train_no`) REFERENCES `train` (`train_no`),
  ADD CONSTRAINT `ticket_ibfk_2` FOREIGN KEY (`passenger_id`) REFERENCES `train_user` (`user_id`),
  ADD CONSTRAINT `ticket_ibfk_3` FOREIGN KEY (`compartment_no`) REFERENCES `compartment` (`compartment_no`);

--
-- Constraints for table `ticket_passenger`
--
ALTER TABLE `ticket_passenger`
  ADD CONSTRAINT `ticket_passenger_ibfk_1` FOREIGN KEY (`pnr`) REFERENCES `ticket` (`pnr`);

--
-- Constraints for table `user_phone`
--
ALTER TABLE `user_phone`
  ADD CONSTRAINT `user_phone_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `train_user` (`user_id`);

--
-- Constraints for table `user_train`
--
ALTER TABLE `user_train`
  ADD CONSTRAINT `user_train_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `train_user` (`user_id`),
  ADD CONSTRAINT `user_train_ibfk_2` FOREIGN KEY (`train_id`) REFERENCES `train` (`train_no`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;