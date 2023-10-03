# Introduction to Software Quality and Testing

> *Software Testing is not defined by the words we put, but the actions we take*

**Software**: Collection of computer programs that perform a task.

	- System Software: Device drivers, Utilities
	- Programming Software: Compilers, Interpretters, Debuggers
	- Application Software: Word, Web Browser

**Programs**: Set of instructions.

*Software Testing*:
- is a part of software development process.
- is an activity to detect and identify the defects in the software.
- objective is to release quality product to the client.

Software Quality: 
- Bug free
- Maintainability
- Delivered on time
- Within Budget
- Meets the requirements

> Shifting from Project to Product

Online Defn
- Project is temp, has defined start and end time. Unique.
- Product is a good, service, platform, app etc. Needs to be maintained.

- [Accenture](https://www.accenture.com/us-en/blogs/software-engineering-blog/whats-the-difference-between-a-project-and-a-product)
- [GFG](https://www.geeksforgeeks.org/difference-between-project-and-product/)

Slides Defn
- Project: Software app developed for specific customer/specific customer requirements. Only used by the specific org.
- Product: Software app developed for the market req. and is used by multiple customers.

Software Quality ? (again)
- Field of study and practice that describes the desirable attributes of software products
    - Defect management
    - Quality attributes
"fitness of purpose" not satisfactory defn

Software Quality Model:
- Functional suitability
- Performance efficiency
- Compatibility (Operability)
- Usability
- Reliability
- Security
- Maintainability
- Portability (Transferability)

Quality Concepts:
- Effectiveness
- Efficiency
- Satisfaction
- Safety
- Usability

PMBOK: Quality is a conformance to standards or reqs. [^1]

ISO9000: Totality of features and chars of a product or service that bear on its ability to satisfy stated and implied needs.

Deming PDCA:
- Plan: Improvement to present practices.
- Do: Implement the plan.
- Check: Test to see if the desired results are achieved.
- Act: Implement the corrective action.

Probability of failure-free operation in a specified time measured as MTTF. [atlassian](https://www.atlassian.com/incident-management/kpis/common-metrics), [bmc](https://www.bmc.com/blogs/mtbf-vs-mtff-vs-mttr-whats-difference/)
- MTBF = uptime / no. of failures
- MTTR = total time to repair / no. of repairs
- MTTF = normal avg

Quality Factors:
- Correctness
- Reliability
- Efficiency
- Integrity
- Usability
- Maintainability
- Flexibility
- Testability
- Portability
- Interoperability
- Reusability

PMBOK
quality planning, quality control, quality assurance, quality improvement.

Quality Management:
- Quality Planning
- Quality Assurance (process-oriented, preventing quality issues, focus during creating of product)
- Quality Control (product-oriented, issues in manufacturing products, focus on resulting product)

Cost of Quality: Price of all efforts to achieve product or service quality. Typically should be 3%-5% of project cost.

> This includes the work to build a product or service that conforms to the requirements and all work resulting non-conformance to the requirements.

- Prevention Cost
- Appraisal Cost
- Internal Failure Cost
- External Failure Cost

Defects -> Failures -> Disasters [baeldung](https://www.baeldung.com/cs/software-testing-defect-bug-error-and-failure)

```
Error: Human mistake
Bug: Deviation from expected behavior
Defect: Deviation from actual behavior
Failure: Deviation identified by end user.
```

Testing:
- Planned
- Performed in a reasonable way
- Independent of objective
- Managed

---

#### SDLC

3 P
- People
- Process (Stages)
- Product (Deliverables)

Stages
- Requirements Analysis
- Define
- Design
- Dev (Implementation)
- Test
- Deployment
- Maintain

Why:
- Project tracking, control
- Visibility
- Dev Speed
- Client Reln
- Decreased project risk

Aim:
- Deliver high-quality system
- Work efficiently with the existing and planned infra
- Maximize productivity
- Provide strong management controls
- Lowers the cost of the development.

Phases:
- Planning & Requirement Analysis (Senior members)
- Defining Requirements. (SRS)
- Design the Product Architecture (DDS)
- Development (Code)
- Testing (Test only phase, happens in other phases too)
- Deployment & Maintenance (UAT)

Models:

1. Waterfall
	- Traditional, Linear
	- First
	- Each phase must be completed before the next phase begins, no overlap.
	- Pros
		- Quality of product will be good.
		- No req changes, less chance of finding bugs
		- Less initial invest.
		- Smaller projects
	- Cons
		- No req chages
		- No backtracking
		- Defect continues to later phases

2. Spiral
	- Risk Man - Prototype - Design - Code - Integration - Test - Implementation
	- Clockwise progress
	- Phases
		- Identification
		- Design
		- Construct or Build (POC)
		- Evaluation & Risk analysis (Schedule slippage, cost overrun)
	- Pros
		- Multiple versions, Version Control Model
		- Testing every cycle
		- Customer use model every cycle
		- Req changes allowed every cycle.
	- Cons
		- Req changes allowed every cycle.
		- Internal waterfall
		- No test every phase but every cycle.

3. Iterative: Subset of features, new features each iteration. Incremental updates
4. RAD - Rapid Application Development
	- If project can be broken down into small modules, each module independent separate teams.
	- Combine finally
	- Each module - waterfall (analyse, design, code, test)
	- Phases
		- Req Planning (FAST - Facilitated Application Development Technique)
		- User Desc
		- Construction
		- Cutover: Integrated
	- Short span (2-3 months)
	- Well known req
	- Risk limited
	- Budget

5. Prototype: Sample, blueprint
	- Req -> Prototype -> Customer -> Desgin, Dev, Test

6. V Model
	- Every phase testing
	- Testing is done in || [^2]
	- SRS/BRS/CRS/URS
	- UAT
	- SRS -> HLD -> LLD
	- BRD -> Business Unit People
	- SRS -> Project Mgmt
	- HLD & LLD -> Designers
	- BRD -> Reviews
	- SRS, LLD, HLD -> Testing tech, reviews, walkthroughs, inspection
	- static testing, dynamic testing
	- Walkthrough: Informal, with peers, any time no req.
	- Inspection: Formal, 6-8 ppl,  Mod, Writer, Reader, Scheduled.
	- Verification - Before the software is ready (static, *doing the right thing*) review, walk, inspection
	- Validation - After the software is ready (dynamic, *doing the thing right*) test, unit, integration, system.
	- UAT, System Testing, Integration Testing, Unit Testing
	- Pros
		- Test in each phase, less no. of chance to get bugs later
	- Cons
		- Investment high initial
		- Need dev tests
		- Doc is more
		- || [^2]
	- Modified V: Each phase in evolution, Unit, Component, Integration, System, Acceptance

---

Levels of testing [^3]
- Unit (W)
- Integration (W)
- System (B)
- UAT (B)

Unit Techniues
- Basis Path
- Control Struct - Conditional coverage, loops coverage
- Mutation

System
- GUI, F NF, Usability

UAT
- alpha - customer come to company and do test
- beta - install software in user env and do test

Quality Management
- Planning
- Assurance
- Control
- Improvement

|#|QA|QC|
|-|--|--|
|1|Process|Product|
|2|Prevention|Detect & Correct|
|3|During cycle|After product is built|
|4|Staff func|Line func|
|5|Reviews, audits|Testing levels|


Fish Bone
- Agree on the problem statement
- Agree on main categories of causes
- Brainstorm
- Why this
- Why that
- Why

ETVX - Represent any phase of sw dev
> minimize the delay between defect injection and defect detection
- Entry
- Task
- Verification
- eXit

---

#### Testing

As per ANSI/IEEE 1059, Testing in Software Engineering is a process of evaluating a software product to find whether the current software product meets the required conditions or not.

Types:
- Functional
- Non-Functional
- Maintenance (Regression)

> Software Testing Life Cycle (STLC) is a process used to test software and ensure that quality standards are met
> Software Testing Life Cycle (STLC) is a sequence of specific activities conducted during the testing process to ensure software quality goals are met.
> STLC involves both verification and validation activities.

Phases:
- (Contract Signing)
- Requirement Analysis
	- Identify types of tests to be performed.
	- Gather details about testing priorities and focus.
	- Prepare [Requirement Traceability Matrix (RTM)](https://www.guru99.com/traceability-matrix.html).
	- Identify test environment details where testing is supposed to be carried out.
	- Automation feasibility analysis (if required).
	- RTM
	- Automation feasibility report. (if applicable)
- Test Planning
	- Senior QA manager determines the test plan strategy along with efforts and cost estimates for the project.
	- Determine resources
	- Preparation of test plan/strategy document for various types of testing
	- Test tool selection
	- Test effort estimation
	- Resource planning and determining roles and responsibilities.
	- Training requirement
	- Test Plan Doc
- Test case development
	- Create test cases, automation scripts (if applicable)
	- Review and baseline test cases and scripts
	- Create test data (If Test Environment is available)
	- Test Cases/scripts
	- Test data
- Test Environment setup
	- Understand the required architecture, environment set-up and prepare hardware and software requirement list for the Test Environment.
	- Setup test Environment and test data
	- Perform [smoke test](https://www.guru99.com/smoke-testing.html) on the build
	- Env ready with test data setup
	- Smoke test results
- Test Execution
	- Execute tests as per plan
	- Document test results, and log defects for failed cases
	- Map defects to test cases in RTM
	- Retest the [Defect](https://www.guru99.com/defect-management-process.html) fixes
	- Track the defects to closure
	- RTM complete
	- Test case with results
	- Defect reports
- (Retest Defects)
- Test Cycle closure
	- Evaluate cycle completion criteria based on Time, Test coverage, Cost,Software, Critical Business Objectives, Quality
	- Prepare test metrics based on the above parameters.
	- Document the learning out of the project
	- Prepare Test closure report
	- Test result analysis to find out the defect distribution by type and severity
	- Test closure report
	- Test metrics

**Entry Criteria**: Entry Criteria gives the prerequisite items that must be completed before testing can begin.

**Exit Criteria**: Exit Criteria defines the items that must be completed before testing can be concluded

Test Case:
- Test Case ID
- Test Description
- Assumptions and Pre-Conditions
- Test Data
- Steps to be Executed
- Expected Result
- Actual Result and Post-Conditions
- Pass/Fail

Testing Types
- Based on Method
	- White-Box - test coverage
		- Path
		- Condition
		- Loop
	- Black-Box - functionalities i/o, behavioural
		- Functional (functionality, business req)
		- Non-Functional (perf, usability, scalability)
		- Regression (**after code fixes**, to see if new code is not affecting the existing code)
- Based on Requirements Type
	- Functional (Correctness of internals)
		- Unit
		- Smoke
		- Integration
		- Regression
	- Non-Functional - Reliability, Load, Perf, Accountability (Work in external env)
		- Perf
		- Load
		- Stress
		- Scale
- Based on Life Cycle Phase [^3]
	- Unit (W)
	- Integration (W/B)
	- System (B)
- Based on needs
	- [Regression](https://www.javatpoint.com/regression-testing)
		- Impact analysis (customer business knowledge, developer coding knowledge, test engineer product knowledge)
		- Impact area document
		- Report -> Tech lead
	- Acceptance (Performed by customer before accepting the software into prod)
		- Fitness tool: input values and generate test cases automatically
	- alpha - beta
		- a - limited user base at dev site (sometimes independent team of testers, in-house)
		- b - larger end user base at customer site

[^1]: Project Management Body of Knowledge
[^2]: Parallel
[^3]: White Box / Black Box