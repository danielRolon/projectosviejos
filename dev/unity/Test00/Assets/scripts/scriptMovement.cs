using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class scriptMovement : MonoBehaviour
{
    // Start is called before the first frame update

    private Transform transform;
    
    void Start()
    {
        transform = gameObject.GetComponent<Transform>();
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector2 move = new Vector2(0, 0);

        move.x = Convert.ToSingle(Input.GetKey(KeyCode.D)) - Convert.ToSingle(Input.GetKey(KeyCode.A));

        transform.Translate(move.x * Time.deltaTime, move.y * Time.deltaTime, 0);
    }
}
