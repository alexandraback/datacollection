package personal.codejam.infra;



public interface ICodeJamSolver {

	public void solve() throws Exception;
	
	public void cleanUp() throws Exception;
	
	public String getInputPath();
	
	public String getOutputPath();
}
