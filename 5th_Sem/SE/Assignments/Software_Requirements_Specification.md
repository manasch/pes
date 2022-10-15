# UE20CS303 - Software Requirements Specification

## Blockchain Implementation and Visualization - _Team 2_

## Software Requirements Specification for Blockchain Implementation and Visualization

### Version 1.0 approved

## Prepared by 

- Manas Chebrolu – PES1UG20CS111
- Atharv Tiwari – PES1UG20CS087
- Chetan Gurram – PES1UG20CS112
- Ayush Gupta – PES1UG20CS095
- Aryan Karn – PES1UG20CS080


PES University \
Date: 24/09/2022

---

# Table of Contents
- Table of Contents
- Revision History
1.	Introduction
	1.	Purpose
	1.	Intended Audience and Reading Suggestions
	1.	Product Scope
	1.	References
2.	Overall Description
	1.	Product Perspective
	1.	Product Functions
	1.	User Classes and Characteristics
	1.	Operating Environment
	1.	Design and Implementation Constraints
	1.	Assumptions and Dependencies
3.	External Interface Requirements
	1.	User Interfaces
	1.	Software Interfaces
	1.	Communications Interfaces
4.  Analysis Models
5.	System Features
	1.	System Feature 1
	1.	System Feature 2 (and so on)
6.	Other Nonfunctional Requirements
	1.	Performance Requirements
	1.	Safety Requirements
	1.	Security Requirements
	1.	Software Quality Attributes
	1.	Business Rules
7.	Other Requirements
- Appendix A: Glossary
- Appendix B: Field Layouts
- Appendix C: Requirement Traceability matrix

---

# Revision History

| Name | Date | Reason For Changes | Version |
|------|------|--------------------|---------|
|      |      |                    |         |
|      |      |                    |         |
|      |      |                    |         |

---

# Introduction

## Purpose

The purpose of the project is to simulate and visualize the working of a blockchain to make it easy for a layman to understand the world of blockchain.

## Intended Audience

This project is intended for non-technical users, budding programmers, and crypto-currency enthusiasts.

## Product Scope

The product is a simple web interface to explore blockchain. Its purpose is to help users understand how the blockchain works, which will benefit them in choosing the correct blockchain for actual investment.
The main goal is to have users interact with the blockchain and have fun while learning about the blockchain.

## References

- https://andersbrownworth.com/blockchain/

---

# Overall Description

## Product Perspective

The product stems from the idea of distributed storage, with no single point of failure. It is a follow-on on the famous and existing concept of blockchain. It is a self-contained product that can be used to learn more about the inner workings of a blockchain network.

## Product Functions

- Creation of a block (Mining)
- Validating a block (PoW)
- Maintaining integrity of a block
- Resolving tiebreaks
- Handling transactions
- Web interface

## User Classes and Characteristics

The user class of the product consists of users ranging from little to no technical knowledge to experienced individuals.
The layman will have visuals to guide and help them use the product.

## Operating Environment

Built in Python 3, this software is targeted to Windows 10 or above and Ubuntu 22.04 and above.

## Design and Implementation Constraints

The product will require Python3, without which the program will not work. Due to limited time, a full-fledged GUI will be replaced with a web browser interface that will have its minimum requirements. The customer’s organization will be responsible for maintenance after launch.

## Assumptions and Dependencies

The product assumes that the user installing and running the program will have minimum system requirements. It is also assumed that all the dependencies used will not be deprecated.

---

# External Interface Requirements

## User Interfaces

Sample screen images taken from [here](https://andersbrownworth.com/blockchain/)

- Hash Calculation
- Block Creation and Mining
- Connecting Blocks to form a Blockchain
- Managing Peers
- Transactions

## Software Interfaces

- Web Framework: Python3 Flask
- Web Server: Node.js Web Server
- OS: Windows 10 and above or Ubuntu 22.04 and above

## Communications Interfaces

- Communication Standards: HTTP on TCP

---

# Analysis Models

## Use Case Diagram

- Refer [this](./SE_Project_Use_Case_Diagram.drawio)

---

# System Features

## Creating Blocks

This feature enables users to create new blocks in the blockchain with their inputted data while calculating the hash of the data and the nonce depending on difficulty. This feature is a high priority.
The user creates a new block and enters the data. The block is invalid as the hash doesn’t match until the user mines the block. After mining, the nonce is calculated and the hash matches so the block becomes valid.

1. REQ-1:
	- Users should be able to create blocks.
1. REQ-2:
	- Users should be able to input data to be stored in the created block.
1. REQ-3:
	- Users should be able to mine the block to calculate nonce and make the block valid.

## Modifying Blocks

This feature enables users to change the data and number of blocks in the blockchain. This feature is a high priority.
The user modifies a block. The block and all subsequent blocks are invalid as the hash doesn’t match until the user mines the block. After mining, the nonce is calculated and the hash matches so the block becomes valid. This has to be repeated for all blocks after the block modified for the chain to become valid again.

1. REQ-1:
	- Users should be able to modify the data in blocks.
1. REQ-2:
	- Users should be able to change the block number
1. REQ-3:
	- Users should be able to mine the block and all following ones to make the blockchain valid again.

## Adding new users/peers

This feature enables users to create new peers that can create their own or interact with existing blockchains . This feature is a medium priority.
A new user is created. It can create its own blockchain and can also access other blockchains if given access.

1. REQ-1:
	- Users should be able to create a new peer.
1. REQ-2:
	- Users should be able to create a blockchain with the new peer.
1. REQ-3:
	- Users should be able to handle access of other peers to their blockchain.

## Performing Transactions

This feature helps record transactions done among peers in the blockchain. This feature is a medium priority.
Users can record transaction details and keep it safe on the blockchain, transactions once recorded are published to every peer using the blockchain, due to the high integrity of a block in the blockchain, performing malicious changes would be found and rejected.

1. REQ-1:
	- Users should be able to record new transactions.
1. REQ-2:
	- The transactions should have high integrity
1. REQ-3:
	- Transactions should be verified by each peer.

---

# Other Nonfunctional Requirements

## Performance Requirements

The blockchain must be able to accommodate and validate multiple consecutive transactions in a short period of time. The problem of double spending where each transaction may be propagated as they were created, but they may not be received by the nodes in the order in which they are generated in which case  the 2nd transaction may be validated before the 1st transaction must be avoided. 

## Safety and Security Requirements

Relevant cryptographic hashing/encryption should be used in order to protect stored user data. Vulnerabilities should be mitigated in order to prevent users from gaining admin level access. 

## Software Quality Attributes
The software should be able to run on all stable releases of the user’s desired web browser on both mobile and desktop. All the software’s intended functionalities should be available to use.

## Business Rules
Users will be able to interact with the intended functionalities. However, restrictions will be put such that users will not be able to breach or attempt to corrupt the stored data. 

---

# Appendix

## Appendix A: Glossary

- Nonce: A value that needs to be calculated such that a miner can publish his block into the blockchain.
- Block: A collection of one or many transactions.
- Miner: A member responsible for creating and validating the integrity of a block.
