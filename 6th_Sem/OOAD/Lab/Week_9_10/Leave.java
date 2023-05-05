import java.time.LocalDate;

enum LeaveStatus {
    NEW,
    APPROVED,
    REJECTED
}

enum LeaveType {
    CL,
    SL,
    VL
}

class Employee {
    private String Name;
    private int id;

    Employee(String Name, int id) {
        this.Name = Name;
        this.id = id;
    }

    public String getName() {
        return Name;
    }

    public int getId() {
        return id;
    }

    public String toString() {
        return "\nEmployee Id: " + this.id + "\nEmployee Name: " + this.Name;
    }
}

class Leave {
    protected Employee employee;
    protected LeaveStatus leaveStatus = LeaveStatus.NEW;
    protected LeaveType leaveType;
    protected String approvedBy;
    protected LocalDate requestDate;
    protected LocalDate approvalDate;
    protected String comments = "";

    public Employee getEmployee() {
        return this.employee;
    }

    public LeaveStatus getLeaveStatus() {
        return this.leaveStatus;
    }

    public void setLeaveStatus(LeaveStatus status) {
        this.leaveStatus = status;
    }

    public LeaveType getLeaveType() {
        return this.leaveType;
    }

    public String getApprovedBy() {
        return this.approvedBy;
    }

    public void setApprovedBy(String approvedBy) {
        this.approvedBy = approvedBy;
    }
    
    public LocalDate getRequestDate() {
        return this.requestDate;
    }

    public LocalDate getApprovalDate() {
        return this.approvalDate;
    }

    public void setApprovalDate(LocalDate approvedDate) {
        this.approvalDate = approvedDate;
    }

    public String getComments() {
        return this.comments;
    }

    public void setComments(String comments) {
        this.comments = comments;
    }

    public String toString() {
        return this.employee.toString() + "\n" + "\nComments: " + this.comments
        + "\nRequest Date: " + this.requestDate.toString() + "\nApproval Date: " + this.approvalDate.toString()
        + "\nApproved By: " + this.approvedBy + "\nLeave Type: " + this.leaveType + "\nLeave Status: " + this.leaveStatus;
    }
}

class SickLeave extends Leave {
    protected LocalDate leaveDate;
    
    SickLeave(Employee emp, LocalDate requestDate, LocalDate leaveDate) {
        this.employee = emp;
        this.requestDate = requestDate;
        this.leaveDate = leaveDate;
        this.leaveType = LeaveType.SL;
    }

    public String toString() {
        return "\n---Sick Leave Status---\n" + super.toString() + "\nLeave Date: " + this.leaveDate.toString();
    }
}

class CasualLeave extends Leave {
    protected LocalDate leaveDate;
    protected String leaveReason;

    CasualLeave(Employee emp, LocalDate requestDate, LocalDate leaveDate, String reason) {
        this.employee = emp;
        this.requestDate = requestDate;
        this.leaveDate = leaveDate;
        this.leaveReason = reason;
        this.leaveType = LeaveType.CL;
    }

    public String toString() {
        return "\n---Casual Leave Status---\n" + super.toString() + "\nLeave Date: " + this.leaveDate.toString() + "\nReason: " + this.leaveReason;
    }
}

class VacationLeave extends Leave {
    protected LocalDate startDate;
    protected LocalDate endDate;
    
    VacationLeave(Employee emp, LocalDate requestDate, LocalDate startDate, LocalDate endDate) {
        this.employee = emp;
        this.requestDate = requestDate;
        this.startDate = startDate;
        this.endDate = endDate;
        this.leaveType = LeaveType.VL;
    }

    public String toString() {
        return "\n---Vacation Leave Status---\n" + super.toString() + "\nStart Date: " + this.startDate.toString() + "\nEnd Date: " + this.endDate.toString();
    }
}

interface LeaveHandler {
    void setNextHandler(LeaveHandler nextHandler);
    void handleLeave(Leave leave);
}

abstract class BaseLeaveHandler implements LeaveHandler {
    private LeaveHandler nextHandler;

    @Override
    public void setNextHandler(LeaveHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleLeave(Leave leave) {
        if (canHandle(leave)) {
            processLeave(leave);
        }
        else if (nextHandler != null) {
            nextHandler.handleLeave(leave);
        }
        else
            return;
    }

    protected abstract boolean canHandle(Leave leave);
    protected abstract void processLeave(Leave leave);
}

class TechLeadLeaveHandler extends BaseLeaveHandler {
    @Override
    public boolean canHandle(Leave leave) {
        return (leave.getLeaveType() == LeaveType.SL);
    }

    @Override
    public void processLeave(Leave leave) {
        leave.setApprovalDate(LocalDate.now());
        leave.setApprovedBy("Tech Lead");
        leave.setLeaveStatus(LeaveStatus.APPROVED);

        leave.setComments("Sick Leave processed by Tech Lead");
    }
}

class ProjectManagerHandler extends BaseLeaveHandler {
    @Override
    public boolean canHandle(Leave leave) {
        return (leave.getLeaveType() == LeaveType.CL);
    }

    @Override
    public void processLeave(Leave leave) {
        leave.setApprovalDate(LocalDate.now());
        leave.setApprovedBy("Project Manager");
        leave.setLeaveStatus(LeaveStatus.APPROVED);

        leave.setComments("Casual Leave processed by Project Manager");
    }
}

class DirectorLeaveHandler extends BaseLeaveHandler {
    @Override
    public boolean canHandle(Leave leave) {
        return (leave.getLeaveType() == LeaveType.VL);
    }

    @Override
    public void processLeave(Leave leave) {
        leave.setApprovalDate(LocalDate.now());
        leave.setApprovedBy("Director");
        leave.setLeaveStatus(LeaveStatus.APPROVED);

        leave.setComments("Vacation Leave process by Director");
    }
}

class Main {
    public static void main(String[] args) {
        TechLeadLeaveHandler techLead = new TechLeadLeaveHandler();
        ProjectManagerHandler projectManager =  new ProjectManagerHandler();
        DirectorLeaveHandler director = new DirectorLeaveHandler();

        techLead.setNextHandler(projectManager);
        projectManager.setNextHandler(director);

        Employee emp1 = new Employee("Bob", 1);
        Employee emp2 = new Employee("Sob", 2);
        Employee emp3 = new Employee("Lob", 3);

        Leave newSickLeave = new SickLeave(emp1, LocalDate.now(), LocalDate.of(2023, 04, 19));
        Leave newCasualLeave = new CasualLeave(emp2, LocalDate.now(), LocalDate.of(2023, 04, 21), "Relatives visiting");
        Leave newVacationLeave = new VacationLeave(emp3, LocalDate.now(), LocalDate.of(2023, 4, 20), LocalDate.of(2023, 5, 4));

        techLead.handleLeave(newSickLeave);
        techLead.handleLeave(newCasualLeave);
        techLead.handleLeave(newVacationLeave);

        System.out.println(newSickLeave.toString());
        System.out.println(newCasualLeave.toString());
        System.out.println(newVacationLeave.toString());
    }
}
