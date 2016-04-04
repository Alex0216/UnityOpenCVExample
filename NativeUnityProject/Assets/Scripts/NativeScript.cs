using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class NativeScript : MonoBehaviour
{

    [DllImport("NativeLibExample")]
    private static extern int returnInt();


	// Use this for initialization
	void Start ()
	{
	    int result = returnInt();
	    Debug.Log("Native function result: " + result);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
