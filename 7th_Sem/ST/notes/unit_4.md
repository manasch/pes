# Acceptance Testing

- Testing done in accordance with customer specified criteria
- Typically criteria is pre-defined and mutually agreed
- Done at specific delivery instances
- Done under customer controlled env.
- Business functionality, May cover some non-functional requirement.
- Legal & Statutory requirements.
- Critical for business purpose, without defined acceptance criteria, managing closure is difficult.

#### Typical test cases cover
- Critical func
- Most used func
- End-to-end scenarios

- Happens "On-Site" after careful environment setting.
- Stand by team is required
- Team with good business knowledge and application working knowledge
- Major defects - break the acceptance test

#### Challenges
- Hard to specify
- Dev team might omit what is not in acceptance test (in the prior phases)
- Results need to be carefully analyzed

#### Alpha Testing
- Done by internal developer and QA teams. Main goal to ensure that the software is functional, reliable, and free of any defects or errors.
- Data is not real and typically small.

#### Beta Testing
- Typically for products, more so for product releases, rejections in markets place is a huge risk.
- Incentivized participation
- In a real world setting, users create their own dataset, potential customers.

---

# Non-Functional Test

Testing the abilities of the system.

- **Reliability**: Runs error free over a period of time or num of iterations.
- **Scalability**: Determines maximum capability of the product.
- **Performance**: Evaluate the time taken or response time of the product.
- **Stress**: Evaluate system beyond specified limits.
- **Interoperability**: If two modules can communicate with each other.
- **Security**
- **Compatibility**

#### Scalability
- Ability of a system to handle increasing amounts of work without unacceptable level of performance
	- Vertical
	- Horizontal
- Resource utilization is exponential beyond a point
- Increases N% for m times the resource. Suitable optimal configuration settings for a required scalability setting.

#### Reliability
- Probability of failure-free software operation for a specified period of time or num of operations.
- Focus more on the frequently used operations.
- Executed continuously for a given duration or iterations.
- `#` of failures in a given run.
- MTBF
- Identifying causes of failures is the hardest

#### Stress Test
- Test the behavior of the system under very severe conditions, high load / low resources, good system should gracefully degrade.
- Since this is also randomly applied over a period of time, it is similar to reliability tests.
- As the resource / load ratio decreases, performance should go down. Should recover symmetrically, should stop gracefully in extreme conditions

#### Performance Test
- Test cases would focus on getting response time and throughput for different operations, under defined environment and tracking resources consumption.
- Measure accurately the response time and throughput under a defined env and load.
- Measure and improve
- Gauge against competing or standard products.
- Methodology
	- Establish perf reqs
	- Design test cases
	- Automate
	- Conduct testing and collect results
	- Analyze results
	- Tune performance
	- Benchmark
	- Establish needed config size.
- Test automation:
	- In itself a software dev activity
	- Specialized tools or shell scripts driven batch programs
	- Input / Config parameters are not hard coded
	- Modularization and Reusability
	- Selective and Random execution
	- Reporting data and test logs
	- Maintainable and reliable

- Outcomes of non-functional testing is more than a pass or fail, data collections, data analysis, trend analysis.
- Testing to improve product quality
- Gain confidence
- Tunable parameters

#### Security Testing
- Both static and dynamic
- Weak spots are called security vulns
- OWASP Certs and standards

#### Other NF Test Types
- Endurance testing
- Load testing
- Compatibility testing
- Standards Compliance testing
- Usability testing
- Accessibility & Internationalization testing

---

# Regression Testing

- Regression testing is selective re-testing of the system with an objective to ensure that the bug fixes work and those bug fixes have not caused any unintended / undesirable side-effects in the system.
- Not just defects, but even for modifications.

#### Types
- Final regression: Cook time (gold master build), to ensure same build reaches the customer, have full confidence on product prior release
- Regular regression: Validate product builds between test cycles, used for making intermediate releases (beta, alpha)

#### Methodology
- Criteria for selecting regression test cases
- Smoke tests: Ensures that basic functionality works and indicates that the build can be considered for further testing.
- Classifying test cases: Priority 1, 2, 3, 4
- Selecting test cases: Bug fixes work, no side-effects
- Resetting test cases for regression testing: NOTRUN or EXECUTE AGAIN flags
	- Done when there is a major change
	- Change in build that affects the product
	- In a large release cycle where it hasn't been run in a while
	- Final regression test cycle
	- In a situation where expected results could by different from history.
- Conclude results

> [!IMPORTANT]
> Emphasis is more on the criticality of the bug fixes than the criticality of the defect itself
> More positive test cases than negative test cases for final regression
> Constant set of regression test cases is rare

#### Popular strategies
- Regress all
- Priority Based
- Regress changes (grey box testing)
- Random regression
- Context-based dynamic regression

#### Best practices
- Regression can be used for all types of testing and all phases of testing
- Mapping defect numbers with test case result improves regression quality
- Create and execute regression test bed daily

---

# Agile & Ad-Hoc

#### Iterative Testing
- Each of the reqs is at a different phase
- Testing needs to focus on the current requirements
- More re-testing effort
- Ensure that all reqs continue to work

#### Agile Testing
- Follows best practices of agile dev framework
- Takes an incremental approach to testing.
- Advantages
	- Early detection
	- Continuous integration
	- Risk reduction
	- Enhances product quality
	- Cost-efficiency
- Methodology
	- Impact assessment
	- Planning
	- Daily stand-ups
	- Reviews

#### Defect Seeding
- Method of intentionally introducing defects into a product to check the rate of detection and residual defects.
- Detect errors

#### AdHoc Testing
- Without proper planning and doc
- Done after formal testing
- Not structured approach
- Hard to replicate

| When you want to                                                  | Most effective adhoc testing |
| ----------------------------------------------------------------- | ---------------------------- |
| Randomly test product after all planned test cases are done       | Monkey Testing               |
| Capture programmatic errors early by devs and testers             | Buddy Testing                |
| Test the new product / domain tech                                | Exploratory Testing          |
| Leverage experience of a senior tester as well as of a new commer | Pair Testing                 |
| Deal with changing requirements                                   | Iterative Testing            |
| Make frequent releases with customer involvement                  | Agile / Extreme Testing      | 

---

# Software Testing Tools

#### Types:
- Static Testing Tools: Path Test, Coverage analysers
- Dynamic Testing Tools: Beds, Emulators

#### Selenium
- Open source
- Automated testing tool used to test web applications
- No mobile apps
- Extensible
- Executes test in parallel
- No official user support
- No built-in object repo

#### Test Management Tools
- Used to store info on how testing is to be done, plan test activities, report status of quality
- Bugzilla, Jira
- Core Features
	- Requirements Management
	- Test Case Management
	- Defect Tracking

#### Bugzilla
- Open source
- Track bugs and issues
- Very advanced search system
- Helps keep track of unresolved problems
- Time tracking
- No drag and drop, poor user interface
- Does not support **Kanban projects**
- Not recommended for agile project dev

#### Jira
- Commercial software
- Bug tracking and agile project management
- Use-cases:
	- Project Management
	- Task Management
	- Agile Planning
- Intuitive UI
- Supports integration with third party apps.
- Can be complex
- Load times for large volumes of data

---
