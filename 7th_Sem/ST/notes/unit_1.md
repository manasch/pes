# Introduction to Software Quality and Testing

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

[^1]: Project Management Body of Knowledge
[^2]: Parallel