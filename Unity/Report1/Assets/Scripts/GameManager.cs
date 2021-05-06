using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public GameObject gameoverText;
    public Text timeText;
    public Text recordText;
    public Text IDText;
    public Text nameText;

    private float surviveTime;
    private bool isGameover;

    // Start is called before the first frame update
    void Start()
    {
        SettingInfo();
        IDText.text = PlayerPrefs.GetString("ID");
        nameText.text = PlayerPrefs.GetString("name");

        surviveTime = 0;
        isGameover = false;

    }

    // Update is called once per frame
    void Update()
    {
        if (!isGameover) {
            surviveTime += Time.deltaTime;
            timeText.text = "Time : " + (int)surviveTime;
        }
        else {
            if(Input.GetKeyDown(KeyCode.R)) {
                SceneManager.LoadScene("SampleScene");
            }
        }
    }
    
    // 총알에 부딪혔을 시 게임 종료
    public void GameOver() {
        isGameover = true;
        gameoverText.SetActive(true);

        recordText.text = "Game Over!";
    }

    public void EndGame() {
        isGameover = true;
        gameoverText.SetActive(true);
        
        float bestTime = PlayerPrefs.GetFloat("BestTime");
    
        if(surviveTime < bestTime) {    // 시간이 적게 걸릴 수록 최고기록
            bestTime = surviveTime;
            PlayerPrefs.SetFloat("BestTime", bestTime);
        }

        recordText.text = "Best Time : " + (int)bestTime;
    }

    // 학번과 이름을 PlayerPrefs에 저장시켜주는 함수
    public void SettingInfo() {
        PlayerPrefs.SetString("ID", "2019112540"); // 학번을 문자열 형태로 저장함
        PlayerPrefs.SetString("name", "이승민");
    }
}
