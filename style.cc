:root {
  --primary: #2563eb;
  --primary-dark: #1d4ed8;
  --accent: #10b981;
  --bg-gradient: linear-gradient(135deg, #0f172a 0%, #1e293b 100%);
  --card-bg: rgba(255, 255, 255, 0.95);
  --text-main: #0f172a;
  --text-muted: #64748b;
  --border-color: #e2e8f0;
}

body {
  font-family: 'Plus Jakarta Sans', sans-serif;
  background: var(--bg-gradient);
  min-height: 100vh;
  margin: 0;
  padding: 2rem 1rem;
  color: var(--text-main);
  box-sizing: border-box;
}

.app-container {
  max-width: 1100px;
  margin: 0 auto;
}

.app-header {
  margin-bottom: 2rem;
  color: #ffffff;
}

.logo {
  display: flex;
  align-items: center;
  gap: 1rem;
}

.logo-icon {
  font-size: 2.8rem;
  background: rgba(255, 255, 255, 0.1);
  padding: 0.5rem 0.8rem;
  border-radius: 16px;
  backdrop-filter: blur(10px);
}

.app-header h1 {
  margin: 0;
  font-size: 2.2rem;
  font-weight: 800;
  letter-spacing: -0.5px;
}

.app-header p {
  margin: 0.2rem 0 0 0;
  color: #94a3b8;
}

.main-layout {
  display: grid;
  grid-template-columns: 1fr 1.2fr;
  gap: 2rem;
}

@media (max-width: 900px) {
  .main-layout {
    grid-template-columns: 1fr;
  }
}

.card {
  background: var(--card-bg);
  border-radius: 20px;
  padding: 2rem;
  box-shadow: 0 20px 40px rgba(0, 0, 0, 0.2);
}

.form-card h2 {
  margin-top: 0;
  margin-bottom: 1.5rem;
  font-size: 1.3rem;
  color: #1e293b;
  border-bottom: 2px solid #f1f5f9;
  padding-bottom: 0.75rem;
}

.form-group {
  margin-bottom: 1.25rem;
  display: flex;
  flex-direction: column;
}

label {
  font-weight: 600;
  font-size: 0.9rem;
  margin-bottom: 0.4rem;
  color: #334155;
}

input[type="text"],
input[type="number"],
select {
  padding: 0.85rem 1rem;
  border: 2px solid var(--border-color);
  border-radius: 12px;
  font-size: 1rem;
  font-family: inherit;
  transition: all 0.2s ease;
  background: #ffffff;
}

input:focus, select:focus {
  outline: none;
  border-color: var(--primary);
  box-shadow: 0 0 0 4px rgba(37, 99, 235, 0.15);
}

.checkbox-group {
  display: flex;
  gap: 0.75rem;
  margin: 1.5rem 0;
  flex-wrap: wrap;
}

.checkbox-card {
  flex: 1;
  min-width: 120px;
  display: flex;
  align-items: center;
  gap: 0.5rem;
  padding: 0.75rem 0.85rem;
  background: #f8fafc;
  border: 2px solid var(--border-color);
  border-radius: 12px;
  cursor: pointer;
  font-weight: 600;
  font-size: 0.85rem;
  transition: all 0.2s ease;
}

.checkbox-card:hover {
  background: #f1f5f9;
}

.checkbox-card input[type="checkbox"] {
  width: 18px;
  height: 18px;
  accent-color: var(--primary);
}

.btn-primary {
  width: 100%;
  background: linear-gradient(135deg, var(--primary) 0%, var(--primary-dark) 100%);
  color: #ffffff;
  padding: 1rem;
  border: none;
  border-radius: 12px;
  font-size: 1.05rem;
  font-weight: 700;
  cursor: pointer;
  box-shadow: 0 8px 20px rgba(37, 99, 235, 0.3);
  transition: transform 0.2s ease, box-shadow 0.2s ease;
}

.btn-primary:hover {
  transform: translateY(-2px);
  box-shadow: 0 12px 25px rgba(37, 99, 235, 0.4);
}

.empty-state {
  text-align: center;
  padding: 4rem 2rem;
  color: var(--text-muted);
}

.empty-icon {
  font-size: 3.5rem;
  margin-bottom: 1rem;
}

.error-banner {
  background: #fef2f2;
  border: 2px solid #fca5a5;
  color: #991b1b;
  padding: 1rem 1.25rem;
  border-radius: 12px;
  font-weight: 700;
  display: flex;
  align-items: center;
  gap: 0.75rem;
  margin-bottom: 1.5rem;
}

.bill-card {
  background: #ffffff;
  border-radius: 20px;
  padding: 2rem;
  box-shadow: 0 20px 40px rgba(0, 0, 0, 0.2);
}

.bill-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  border-bottom: 2px solid #f1f5f9;
  padding-bottom: 1rem;
  margin-bottom: 1.25rem;
}

.bill-header h2 {
  margin: 0;
  font-size: 1.4rem;
  color: #0f172a;
}

.badge {
  background: #e0e7ff;
  color: #3730a3;
  padding: 0.35rem 0.85rem;
  border-radius: 20px;
  font-size: 0.8rem;
  font-weight: 700;
}

.summary-rows {
  display: flex;
  flex-direction: column;
  gap: 0.65rem;
}

.row {
  display: flex;
  justify-content: space-between;
  font-size: 0.95rem;
  color: #475569;
}

.row strong {
  color: #0f172a;
}

.row.discount {
  color: #059669;
}

.row.total {
  border-top: 2px solid #0f172a;
  padding-top: 0.85rem;
  margin-top: 0.5rem;
  font-size: 1.25rem;
  color: #0f172a;
}

.wallet-box {
  background: linear-gradient(135deg, #ecfdf5 0%, #d1fae5 100%);
  border: 1px solid #a7f3d0;
  color: #065f46;
  padding: 1.25rem;
  border-radius: 14px;
  margin: 1.5rem 0;
  font-size: 0.95rem;
}

.wallet-box h4 {
  margin: 0 0 0.4rem 0;
  font-size: 1.05rem;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.table-wrapper {
  margin-top: 1.5rem;
  overflow-x: auto;
}

.table-wrapper h3 {
  margin-bottom: 0.75rem;
  font-size: 1rem;
  color: #1e293b;
}

table {
  width: 100%;
  border-collapse: collapse;
  font-size: 0.85rem;
}

th, td {
  padding: 0.65rem 0.85rem;
  text-align: left;
  border-bottom: 1px solid #e2e8f0;
}

th {
  background: #f8fafc;
  color: #475569;
  font-weight: 700;
}

tr:nth-child(even) {
  background: #fdfdfd;
}