# Black Box Testing

- Functionality of software without peering into its internal structure or coding.
- Primary source of black box testing is a SRS that is stated by the customer.
- Done with
	- Only the functional knowledge of the system
	- Need not know about the internals

##### Steps for Black Box Testing

1. Based on specification of requirements, so it is examined in the beginning.
2. Create positive and adverse test case scenarios.
3. Various other test cases such as decision table, all pairs test, equivalent division, error estimation, cause-effect graph, etc.
4. Execution of all these test cases.
5. Tester compares the expected output against the actual output.
6. Final step, flaws in the software are cured and tested again.

> [!IMPORTANT]
> Considering the specification of the requirements. (This line comes up a lot of times)

- Test cases can be created from the working descriptions of the software, including requirements, designing parameters and other specifications.
- For testing, the test designer selects both positive test scenario and adverse ones.

##### Types of Black Box Testing

- Functional: Related to the functional requirements of a system.
- Non-Functional: Not related to testing specific functionality, but other aspects such as performance, scalability, usability.
- Regression: Regression testing done after code fixes, to see if the updated / new code has not affected any of the existing code.

##### Common Tools

- Varies depending on the type of testing that is being done.
- Functional / Regression - QTP, Selenium
- Non-Functional - LoadRunner, Jmeter.

#### Difference between W and B testing

| Black                                              | White                                                    |
| -------------------------------------------------- | -------------------------------------------------------- |
| No knowledge of internal struct or code            | Needs knowledge of internal struct and code              |
| Higher level testing such as functional            | Lower level testing such as unit and integration         |
| Concentrates on functionality of system under test | Concentrates on the actual code                          |
| Requires the SRS                                   | Requires the design docs, data flow diagrams, flowcharts |
| Done by testers                                    | Done by devs                                             |

#### Why

- Beneficial for testing usability of the software
- Overall functionality of the system under test
- Black box testing gives you a broader pic of the software
- This approach sees an app from the user's POV
- Test the software as a whole system rather than different modules

#### Advantages

- Well suited and efficient for large code segments
- Code access is not required
- User's POV separated
- No requirement of skilled testers.

#### Techniques for Black Box Testing

- Requirements Based Testing
	- Genesis of RTM
	- Done to ensure that all reqs in SRS are tested.
	- Difference between implicit and explicit reqs.
	- Review to ensure they are consistent, complete and testable.
	- Review enables translation of the implied reqs to stated reqs.
- Positive and Negative Testing
	- Ensure valid test cases give correct output.
	- Ensure invalid test cases don't break the system.
- Specification Based Testing
	- Anything like a written doc, collection of use cases.
	- Also known as black-box or input/output driven testing.
	- Appropriate at all levels of testing where specification exists.
		- Equivalence Partitioning
		- Boundary Value Analysis (2<sup>n</sup>)
		- Decision Tables
		- State Transition (Triggers)

---

# Grey Box Testing

- A software testing method to test the software application with partial knowledge of the internal working structure.
- Combination of black box and white box. Because it involves access to the internal coding to design the test cases, and testing practices are done at functionality level as black box testing.

> [!NOTE]
> Not necessary that the tester must design the test cases from source code.

Ex: Changing the hyperlink in html and seeing the change in real time.

#### Steps

1. Select and identify inputs from black box and white box testing inputs.
2. Identify expected output from these selected inputs.
3. Identify all the major paths to traverse through during the testing period.
4. Identify sub-functions which are the part of main functions to perform deep level testing.
5. Identify inputs for subfunctions.
6. Executing a test case for subfunctions.
7. Verification of the correctness of result.

#### Advantages

- Provides combined benefits of both white and black box testing.
- Combines input of devs as well as testers to improve overall product quality.
- Reduces the overhead of long process of testing functional and non-functional types.
- **Gives enough free time for a dev to fix defects.**
- Testing is done from the user point of view rather than a designer point of view.

#### Techniques

- Matrix Testing: Defining all the vars that exist in their programs.
- Regression Testing
- **OAT / Orthogonal Array Testing**: Provides maximum code coverage with minimum test cases.
- Pattern Testing: Performed on historical data of previous system defects.

---

# Test Management

#### Project

- Is a temporary endeavor to create a unique product or service.
- Aimed at creating a unique product or service, setting it apart from others in some distinctive way.
- Has a clear and predefined start and end date.
- End result, possesses distinctive features that set it apart from others.
- Even testing can qualify as a project on its own.

- Define the overarching principles that guide your testing approach
- Highlight importance of both product func and testing process.

##### Break down the strat

- Automatoin
- Test Data
- Team / Third Party
- Test Record Management
- Test Defect Management
- Controls for Testing
- Interface with Other Teams / Customer
- Test Metrics
- Alignment with product release.

#### Facets of Test Planning

- Scope Management
	- Release
	- Features
	- Priority
- Decide test strat / approach
- Setting up criteria for testing
- Identifying staff skill sets and training.
	- Compliment
	- Supplement
- Identifying the test env
- Identifying test deliverables
	- Test Plan
	- Test Case Design Specs
	- Post-Testing
	- Test Data / Bed
	- Logs
	- Summary / Reports
- Test Estimation
	- Size
	- Effort
	- Resources
	- Elapsed Time Req
- Test WBS and Scheduling
- Dependencies
- Risk Management
	- Unclear Reqs
		- Engage the testing team from start
	- Schedule Dependency
		- Implement backup tasks and parallel automation
	- Insufficient test time
		- Utilize the v model and establish clear entry / exit criteria
	- Critical defects
		- Identify and address show stopper bugs
	- Non availability of skilled testers
		- showcase career paths to attract and retain skilled testers
- Test Management
	- Test Process Management
	- Test Infra Management
		- Test Case Repo (TCDB)
		- SCM (Artefact config database)
		- Defect repo (DR)
	- People Management
	- Integrating with product release
- Test Reporting
	- Dijkstra's Doctrine

#### Best Practices

- Usage of process models: Adopt CMMI or TMM
- Foster Collaboration
- Leverage Tech: Utilize an integrated SCM-DR-TCDB infra

---

# Defect Management

1. Discovery
2. Categorize
3. Resolution
4. Verification
5. Closure
6. Report

Stages

1. Defect Prevention
2. Deliverable Baseline
3. Defect Discovery
4. Defect Resolution
5. Process Improvement
	1. Look into low priority defects
	2. Still considered critical
6. Defect Closure

