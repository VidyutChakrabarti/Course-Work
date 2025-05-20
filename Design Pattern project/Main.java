
import java.util.*;
import java.time.LocalDateTime;

// 1. Observer Pattern
interface FinancialObserver {
    void update(String category, double amount, String description);
}

class Account implements FinancialObserver {
    private String accountId;
    private String accountName;
    private double balance;

    public Account(String accountId, String accountName, double initialBalance) {
        this.accountId = accountId;
        this.accountName = accountName;
        this.balance = initialBalance;
    }

    @Override
    public void update(String category, double amount, String description) {
        System.out.printf("Alert for %s: %s - $%.2f (%s)%n", 
            accountName, category, amount, description);
    }
}

class FinancialActivityMonitor {
    private List<FinancialObserver> observers = new ArrayList<>();
    private Map<String, List<Transaction>> transactions = new HashMap<>();

    public void attach(FinancialObserver observer) {
        observers.add(observer);
    }

    public void recordTransaction(String category, double amount, String description) {
        Transaction transaction = new Transaction(category, amount, description);
        transactions.computeIfAbsent(category, k -> new ArrayList<>()).add(transaction);
        notifyObservers(category, amount, description);
    }

    private void notifyObservers(String category, double amount, String description) {
        for (FinancialObserver observer : observers) {
            observer.update(category, amount, description);
        }
    }
}

class Transaction {
    private String category;
    private double amount;
    private String description;
    private LocalDateTime timestamp;

    public Transaction(String category, double amount, String description) {
        this.category = category;
        this.amount = amount;
        this.description = description;
        this.timestamp = LocalDateTime.now();
    }
}

// 2. Singleton Pattern
class FinancialDataManager {
    private static FinancialDataManager instance;
    private Map<String, Object> financialData = new HashMap<>();

    private FinancialDataManager() {}

    public static synchronized FinancialDataManager getInstance() {
        if (instance == null) {
            instance = new FinancialDataManager();
        }
        return instance;
    }

    public void updateData(String key, Object value) {
        financialData.put(key, value);
    }

    public Object getData(String key) {
        return financialData.get(key);
    }

    public void recordIncome(double amount, String source) {
        updateData("lastIncomeAmount", amount);
        updateData("lastIncomeSource", source);
    }

    public void recordExpense(double amount, String category) {
        updateData("lastExpenseAmount", amount);
        updateData("lastExpenseCategory", category);
    }
}

// 3. Strategy Pattern
interface InvestmentStrategy {
    void executeStrategy(double amount);
    String getDescription();
}

class ConservativeStrategy implements InvestmentStrategy {
    @Override
    public void executeStrategy(double amount) {
        System.out.printf("Investing $%.2f with conservative strategy: 60%% bonds, 30%% blue-chip stocks, 10%% cash%n", amount);
    }

    @Override
    public String getDescription() {
        return "Conservative Strategy: Focus on capital preservation with low-risk investments";
    }
}

class AggressiveStrategy implements InvestmentStrategy {
    @Override
    public void executeStrategy(double amount) {
        System.out.printf("Investing $%.2f with aggressive strategy: 80%% stocks, 15%% high-yield bonds, 5%% cash%n", amount);
    }

    @Override
    public String getDescription() {
        return "Aggressive Strategy: Focus on growth with higher-risk investments";
    }
}

class InvestmentManager {
    private InvestmentStrategy strategy;

    public void setStrategy(InvestmentStrategy strategy) {
        this.strategy = strategy;
    }

    public void invest(double amount) {
        if (strategy != null) {
            strategy.executeStrategy(amount);
        } else {
            System.out.println("Please set an investment strategy first.");
        }
    }
}

// 4. Template Method Pattern
abstract class BudgetTemplate {
    // Template method
    public final void createBudget(double income) {
        allocateNecessities(income);
        allocateDiscretionary(income);
        allocateSavings(income);
        displayBudgetSummary(income);
    }

    protected abstract void allocateNecessities(double income);
    protected abstract void allocateDiscretionary(double income);
    protected abstract void allocateSavings(double income);

    protected void displayBudgetSummary(double income) {
        System.out.println("\nBudget Summary for Income: $" + income);
    }
}

class CustomBudget extends BudgetTemplate {
    private Map<String, Double> allocations = new HashMap<>();

    @Override
    protected void allocateNecessities(double income) {
        double necessities = income * 0.5; // 50% for necessities
        allocations.put("Housing", income * 0.3);
        allocations.put("Utilities", income * 0.1);
        allocations.put("Food", income * 0.1);
        System.out.printf("Allocated $%.2f for necessities%n", necessities);
    }

    @Override
    protected void allocateDiscretionary(double income) {
        double discretionary = income * 0.3; // 30% for discretionary
        allocations.put("Entertainment", income * 0.1);
        allocations.put("Shopping", income * 0.1);
        allocations.put("Dining Out", income * 0.1);
        System.out.printf("Allocated $%.2f for discretionary spending%n", discretionary);
    }

    @Override
    protected void allocateSavings(double income) {
        double savings = income * 0.2; // 20% for savings
        allocations.put("Emergency Fund", income * 0.1);
        allocations.put("Retirement", income * 0.1);
        System.out.printf("Allocated $%.2f for savings and investments%n", savings);
    }

    @Override
    protected void displayBudgetSummary(double income) {
        super.displayBudgetSummary(income);
        allocations.forEach((category, amount) -> 
            System.out.printf("%s: $%.2f%n", category, amount));
    }
}

// Main Application Class
public class Main {
    public static void main(String[] args) {
        // Initialize financial monitoring (Observer Pattern)
        FinancialActivityMonitor monitor = new FinancialActivityMonitor();
        Account checkingAccount = new Account("CHK001", "Checking Account", 5000.0);
        Account savingsAccount = new Account("SAV001", "Savings Account", 10000.0);
        monitor.attach(checkingAccount);
        monitor.attach(savingsAccount);

        // Record transactions
        monitor.recordTransaction("Expense", -50.0, "Grocery Shopping");
        monitor.recordTransaction("Income", 2000.0, "Salary Deposit");

        // Access financial data (Singleton Pattern)
        FinancialDataManager dataManager = FinancialDataManager.getInstance();
        dataManager.recordIncome(5000.0, "Monthly Salary");
        dataManager.recordExpense(1500.0, "Rent");

        // Investment management (Strategy Pattern)
        InvestmentManager investmentManager = new InvestmentManager();
        
        // Conservative investment for retirement
        investmentManager.setStrategy(new ConservativeStrategy());
        investmentManager.invest(10000.0);

        // Aggressive investment for growth
        investmentManager.setStrategy(new AggressiveStrategy());
        investmentManager.invest(5000.0);

        // Budget planning (Template Method Pattern)
        BudgetTemplate budget = new CustomBudget();
        budget.createBudget(5000.0);
        
        new FinancialAppGUI();
    }
}