# Testing

### Unit Testing

- Individual units or components
- Done by devs
- Function, method, procedure, module or object
- Why?
	1. It reduces defect cost.
	2. Saves time and money.
	3. Increases confidence in code maintenance.
	4. Makes code reusable.
	5. Increases development speed.
	6. Makes code more reliable.
	7. Makes debugging more easy.
- Good unit tests server as project docs
- Modes
	- Manual
	- Automated
		- Isolating for more rigorous testing, helps reveal unnecessary between the code
- Pros
	- Can understand functionality by looking at the unit api
	- Refactor code later
	- Modular
- Cons
	- Can't catch every error
	- Only catch unit, no integration (duh)
- Methods
	- Black Box
	- White Box
	- Gray Box (that is used to execute test suites, test methods, test cases and performing risk analysis.)

TDD - XP [^1]
- Write failing automated test
- Remove dupes
- Test-Driven Development (TDD) involves designing and creating tests for each application function, with developers writing new code only when automated tests fail. This prevents code duplication and encourages writing minimal code to pass tests, prioritizing requirement conditions.
- Steps
	- Add a test
	- Run all tests, see if any new test fails
	- Write code
	- Run tests and refactor
	- Repeat
- Pros
	- Affirmative testing
	- TDD makes code simple and clear
	- Reduces the documentation process at dev end

> Refactoring can help mitigate code thrashing, a situation where different developers introduce conflicting changes.

Refactoring improves code by making it:
- More efficient by addressing dependencies and complexities.
- More maintainable or reusable by increasing efficiency and readability.
- Cleaner so it is easier to read and understand.
- Easier for software developers to find and fix bugs or vulnerabilities in the code

Tools
- Junit
- NUnit
- JMockit (Line, Path, Data coverage)
- EMMA (auto) (Method, Line, Block coverage)
- PHPUnit (auto)

---

### White Box

- White Box Testing is the testing based on the knowledge of how the software solution's internal structure is.
- clear box, open, structural, and glass box testing.
- Internal security holes
- Early defect identification
- Early confidence building
- Reduce complexity in integrated/blackbox testing
- Address both functionality and quality aspects
	- Maintainability, reliability, availability
- Cons
	- Miss the big picture
	- Technology skill required
	- Effort
- Types
	- Static
		- Desk Checking
		- Walkthrough (Group, Peers)
		- Inspection
			- Author
			- Moderator
			- Inspector
			- Scribe
	- Structural
		- Unit, F NF, Coverage, Complexity

### Static Testing

- No execution
- Dry run
- Conforms to the reqs

#### Fagan Inspection

Fagan Inspection Docs
- Program code
- Design specifications
- SRS (if needed)
- Any applicable standards and necessary checklists

Inspection Process
- Planning
- Overview
- Individual prep
- Inspection meeting
- Rework
- Follow-up

Pros
- Thorough
- Multiple perspectives
- Effective

Cons
- Logistically Difficult
- Time consuming

Meetings in Fagan
- Preliminary (optional)
- Defect logging
- Follow-up (optional)

Tools: LINT

---

### Structural Testing

- Done by running the exe on the machine

Types;
- unit functional testing
	- quick checks be dev
	- remove obvious error
	- programmer level
- code coverage
	- cover all parts of code
	- map code to required functionality
	- Coverage = (Statements executed / Total statements) * 100
	- Types:
		- statement
		- path (# of paths covered / total # of paths)
		- condition (# of conditions covered / total # of conditions)
		- function (100% possible)
	- Tools (lang dependent)
		- Profilers
		- EMMA
		- Assistance
- code complexity
	- Which of the paths are independent
	- Upper bound on the number of tests to be executed
	- [Cyclomatic complexity](https://www.guru99.com/cyclomatic-complexity.html)[^2]
	- Indication of independent paths

---

### Integration Testing

- Uncovers inter-component interface and functional problems
- Errors
	- Interface mismatch –  Parameters / return value – order, type and other semantics
	- Missing interfaces
	- Service invocation protocol mismatch
	- Error handling across the interfaces
	- Errors due to deployed environment
	- Initializations, closures
	- Configuration errors
- Interfaces
	- Internal
	- External

- Approaches (All are incremental – except System Integration)
	1. Top down
		- Stubs
		- Empty funcs with returns
		- Higher levels first
		- High-level logic
		- Stubs complicate effort
		- Diff to observe data flow
		- Poor support for early release
	2. Bottom up
		- Agile suited
		- Leaf nodes get tested multiple times
		- No stubs
		- Drivers
		- Easy to observe flow of data
		- Poor support for early release
	3. Bi-Directional
		- Combine both
		- Sandwich
	4. System Integration
		- Big Bang
		- Difficult to detect bug
		- High pressure

- Incremental Integration
	- Programming errors related to mismatching interfaces or incorrect assumptions among modules will be detected earlier.
	- Debugging is easier.
	- It offers more flexibility.
	- It enables more efficient use of resources

---

### Scenario Testing

- Software Testing Technique that uses scenarios
- Usually these tests are different from test cases as the test cases are single steps whereas scenarios cover a number of steps.
- A test scenario is a story which describes the usage of the software by an end user
- [https://www.guru99.com/test-scenario.html](https://www.guru99.com/test-scenario.html)

Characteristics:
1. Story
2. Motivating
3. Credible
4. Complex
5. Easy to evaluate

Risks:
1. Complex, many features
2. Not designed for coverage
3. Heavily documented
4. When unstable -> Complicated

How to write test scenarios
1. Read the Requirement Documents
2. Predict End User Usage
3. Determine Scenarios
4. Create Traceability Matrix
5. Review

- System Scenarios
- Use Case Scenarios

Scenario Testing - End to End
- Testing “full aspect of main functionality"

System Integration
- System integration means that all the components of the system are integrated together and tested as an entire unit.
- Pros
	- Saves time, effort
- Cons
	- Difficult to locate problem
	- Root cause difficult to pinpoint
	- High pressure
	- Excessive time for certain component to get ready
- Types
	- Sub System
	- Full
- **Big Bang Integration** – approach in which all software components (modules) are combined at once and make a complicated system. This unity of different modules is then tested as an entity.

|#|Factors|Method|
|--|------|------|
|1|Clear req and design|Top Down|
|2|Dynamically changing req, design, arch|Bottom Up|
|3|Changing arch, stable design|Bi-Directional|
|4|Limited changes to existing arch with less impact|System|

---

### System Testing

- System testing tests a completely integrated system to verify that its compliant with its specified requirements.
- Find defects inter-assemblages and system as a whole.
- FRS / SRS context
- _System testing is the only phase of testing which tests both functional and non-functional aspect of the product_
- When to?
	- Independent perspective
	- Customer perspective
	- Fresh pair of eyes to discover defects
	- Test product behavior in a holistic, complete and realistic environment.
	- F NF

- Functional Testing: validates the software system against the functional requirements/specifications
	- Black box testing
	- manual / automation
- Non Functional Testing: to check non-functional aspects (performance, usability, reliability, etc) of a software application

Types:
- Performance and Load
- Scalability
- Reliability
- Stress
- Interoperability
- Localization

Part of system testing:
- Black-box / White-box / Grey-box
- Functional & Non functional
- Software Performance testing
- Smoke and Sanity testing
- Regression testing
- Installation testing
- Destructive testing
- Usability
- Localization
- Boundary tests
- Startup/shutdown tests
- Platform tests
- Load/stress tests
- Security testing
- Recovery tests

Business Vertical Testing
- Business vertical testing is a process in which a product is being used and tested for different business verticals such as banking, insurance, asset management, etc., and also verifying the business operations and its usage
- Simulation (assumes reqs)
- Replication (acquires data to fully customize)

Beta Testing
- Beta testing is a type of User Acceptance Testing.
- Restricted number of end users.
- Reduces risk of failure, customer validation.

[^1]: Extreme Programming
[^2]: V(G) = E - N + 2 or P + 1 (E - edges, N - nodes, P - predicate nodes(number of conditional nodes))

