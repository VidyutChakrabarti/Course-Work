import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FinancialAppGUI {
    private FinancialActivityMonitor monitor;
    private InvestmentManager investmentManager;
    private BudgetTemplate budget;
    private FinancialDataManager dataManager;

    public FinancialAppGUI() {
        monitor = new FinancialActivityMonitor();
        investmentManager = new InvestmentManager();
        budget = new CustomBudget();
        dataManager = FinancialDataManager.getInstance();

        // Setting up the main JFrame
        JFrame frame = new JFrame("Financial Manager");
        frame.setSize(600, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(4, 1));

        // Panel 1: Transaction Panel (Observer Pattern)
        JPanel transactionPanel = new JPanel();
        transactionPanel.setLayout(new GridLayout(4, 2));

        JLabel transactionTypeLabel = new JLabel("Transaction Type: ");
        String[] transactionTypes = {"Income", "Expense"};
        JComboBox<String> transactionTypeBox = new JComboBox<>(transactionTypes);

        JLabel amountLabel = new JLabel("Amount: ");
        JTextField amountField = new JTextField();

        JLabel descriptionLabel = new JLabel("Description: ");
        JTextField descriptionField = new JTextField();

        JButton recordTransactionBtn = new JButton("Record Transaction");

        transactionPanel.add(transactionTypeLabel);
        transactionPanel.add(transactionTypeBox);
        transactionPanel.add(amountLabel);
        transactionPanel.add(amountField);
        transactionPanel.add(descriptionLabel);
        transactionPanel.add(descriptionField);
        transactionPanel.add(recordTransactionBtn);

        // Transaction button action (Observer Pattern)
        recordTransactionBtn.addActionListener(e -> {
            double amount = Double.parseDouble(amountField.getText());
            String description = descriptionField.getText();
            String category = (String) transactionTypeBox.getSelectedItem();
            monitor.recordTransaction(category, amount, description);
            JOptionPane.showMessageDialog(frame, "Transaction Recorded!");
        });

        // Panel 2: Investment Strategy Panel (Strategy Pattern)
        JPanel investmentPanel = new JPanel();
        investmentPanel.setLayout(new GridLayout(3, 2));

        JLabel strategyLabel = new JLabel("Investment Strategy: ");
        String[] strategies = {"Conservative", "Aggressive"};
        JComboBox<String> strategyBox = new JComboBox<>(strategies);

        JLabel investAmountLabel = new JLabel("Investment Amount: ");
        JTextField investAmountField = new JTextField();

        JButton investBtn = new JButton("Invest");

        investmentPanel.add(strategyLabel);
        investmentPanel.add(strategyBox);
        investmentPanel.add(investAmountLabel);
        investmentPanel.add(investAmountField);
        investmentPanel.add(investBtn);

        // Investment button action (Strategy Pattern)
        investBtn.addActionListener(e -> {
            double investAmount = Double.parseDouble(investAmountField.getText());
            String selectedStrategy = (String) strategyBox.getSelectedItem();
            if (selectedStrategy.equals("Conservative")) {
                investmentManager.setStrategy(new ConservativeStrategy());
            } else {
                investmentManager.setStrategy(new AggressiveStrategy());
            }
            investmentManager.invest(investAmount);
        });

        // Panel 3: Budget Generation Panel (Template Method Pattern)
        JPanel budgetPanel = new JPanel();
        budgetPanel.setLayout(new GridLayout(2, 2));

        JLabel incomeLabel = new JLabel("Monthly Income: ");
        JTextField incomeField = new JTextField();

        JButton generateBudgetBtn = new JButton("Generate Budget");

        budgetPanel.add(incomeLabel);
        budgetPanel.add(incomeField);
        budgetPanel.add(generateBudgetBtn);

        // Budget button action (Template Method Pattern)
        generateBudgetBtn.addActionListener(e -> {
            double income = Double.parseDouble(incomeField.getText());
            budget.createBudget(income);
        });

        // Panel 4: Financial Data Management (Singleton Pattern)
        JPanel dataManagerPanel = new JPanel();
        dataManagerPanel.setLayout(new GridLayout(4, 2));

        JLabel recordIncomeLabel = new JLabel("Record Income: ");
        JTextField recordIncomeField = new JTextField();

        JLabel recordExpenseLabel = new JLabel("Record Expense: ");
        JTextField recordExpenseField = new JTextField();

        JButton recordIncomeBtn = new JButton("Submit Income");
        JButton recordExpenseBtn = new JButton("Submit Expense");

        dataManagerPanel.add(recordIncomeLabel);
        dataManagerPanel.add(recordIncomeField);
        dataManagerPanel.add(recordIncomeBtn);
        dataManagerPanel.add(recordExpenseLabel);
        dataManagerPanel.add(recordExpenseField);
        dataManagerPanel.add(recordExpenseBtn);

        // Income and Expense button actions (Singleton Pattern)
        recordIncomeBtn.addActionListener(e -> {
            double income = Double.parseDouble(recordIncomeField.getText());
            dataManager.recordIncome(income, "User Entry");
            JOptionPane.showMessageDialog(frame, "Income Recorded!");
        });

        recordExpenseBtn.addActionListener(e -> {
            double expense = Double.parseDouble(recordExpenseField.getText());
            dataManager.recordExpense(expense, "User Entry");
            JOptionPane.showMessageDialog(frame, "Expense Recorded!");
        });

        // Adding all panels to the frame
        frame.add(transactionPanel);
        frame.add(investmentPanel);
        frame.add(budgetPanel);
        frame.add(dataManagerPanel);

        // Display the frame
        frame.setVisible(true);
    }
}
