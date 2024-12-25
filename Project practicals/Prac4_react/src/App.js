import './App.css';
import Report1 from './report1'
import Report2 from './report2'
import Report3 from './report3'
import Percentage from './percent'
function App() {
  return (
    <div className="App">
      <header className="App-header">

        <div className="logic" style={{ border: '10px solid black' }}>
          <Report1 />
        </div>
        <div className="logic1" style={{ border: '10px solid black' }}>
          <Report2 />
        </div>

        <div className="logic2" style={{ border: '10px solid black' }}>
          <Report3 />
        </div>
        <div className='logic3' style={{ border: '8px solid black' }}> <Percentage /></div>

      </header>
    </div>
  );
}

export default App;