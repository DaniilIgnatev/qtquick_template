# 🧩 **Requirements Analysis Techniques in Generative AI–Driven Development**

## **1. Natural-Language Parsing and Intent Extraction**

**Objective:** Transform unstructured requirement text into structured, machine-processable representations.
**Technique:** Fine-tuned transformer or multimodal LLMs perform semantic role labeling, entity extraction, and dependency parsing to detect *actors, actions, constraints,* and *quality attributes.*
**Example:**

* *Sadik et al. (2023)* used **LLM-Driven Model-to-Code**, where GPT-4 automatically tags verbs (“user logs in”), nouns (“credential form”), and conditions (“if authentication fails”) to form intermediate **requirement–action triples**.
* *Cheng et al. (2025)* note that 61 % of recent RE tools employ this extraction phase as their entry point, often extending BERT/T5 pipelines with domain lexicons (finance, medical, etc.).

**Strengths:** Fast initial structuring, accessible for non-technical stakeholders.
**Weaknesses:** Ambiguity and hallucination risk; requires domain-specific fine-tuning (Kwizera 2025).

---

## **2. Declarative Constraint Modeling**

**Objective:** Express the *intent* and *rules* of a system independently from procedural implementation.
**Technique:** Convert parsed requirements into constraint networks or logical expressions (e.g., JSON-LD schemas, OWL ontologies, or Prolog-style rules).
**Example:**

* *Fuchs et al. (2024)* define a **Domain-Specific Intermediate Representation (DSIR)** that encodes statements like

  ```
  { "RoomA": { "adjacentTo": "RoomB", "material": "concrete" } }
  ```

  which can later be realized in BIM or UI form.
* *Zhou et al. (2025)*’s **DeclarUI** extends this with a *UI Intent Graph* mapping requirement nodes (“user authenticates”) to layout constraints (“input field → password type”).

**Strengths:** Enables traceability, validation, and explainable automation.
**Weaknesses:** Complex constraint propagation can increase computational cost.

---

## **3. Ontology- and Schema-Based Requirement Representation**

**Objective:** Establish a reusable semantic backbone linking stakeholder terms to design artefacts.
**Technique:** Build or reuse domain ontologies; align extracted requirement tokens with ontology classes; support reasoning with description-logic or graph-embedding models.
**Example:**

* *Vasudevan & Reddivari (2025)* catalogue 28 ontologies (ISO/IEC 25010 quality model, Goal-Model Ontology, etc.) reused by GenAI systems to annotate generated artefacts.
* *DeclarUI* aligns UI elements with a **Semantic Widget Ontology**, enabling cross-project consistency.

**Strengths:** Promotes interoperability and explainability.
**Weaknesses:** High upfront modeling cost; domain evolution may outpace ontology updates.

---

## **4. Multi-Perspective Requirement Clustering**

**Objective:** Detect thematic or conflicting requirement groups for prioritization and ambiguity reduction.
**Technique:** Use unsupervised clustering (K-Means, LSI, topic modeling) on embeddings of requirement sentences; visualize clusters via semantic maps.
**Example:**

* *Cheng et al. (2025)* employed **Cytoscape** to correlate 238 papers’ requirement themes—identifying clusters around *usability*, *security*, and *adaptivity.*
* In UI projects, clusters reveal overlapping intents (“responsive layout,” “accessibility”) to be merged declaratively before synthesis.

**Strengths:** Reveals redundancy or conflict early.
**Weaknesses:** Requires human-in-the-loop validation for correct thematic labeling.

---

## **5. Ambiguity Detection and Disambiguation**

**Objective:** Identify vague, incomplete, or conflicting statements before model generation.
**Technique:**

* Rule-based: detect modal verbs (“should,” “may”).
* ML-based: fine-tune classifiers on annotated ambiguity corpora.
  **Example:**
  *Kwizera (2025)* trains a BERT-based model to assign *clarity scores* (0–1) to each requirement; *DeclarUI* integrates this as a filter before schema generation.

**Strengths:** Enhances downstream accuracy; filters hallucination sources.
**Weaknesses:** Context-dependent ambiguity (business vs UI domain) still challenging.

---

## **6. Traceability Matrix Generation**

**Objective:** Map requirements to design artefacts and test cases for verification and change impact analysis.
**Technique:** Vector similarity between requirement embeddings and code/UI embeddings; graph-based propagation to maintain lineage.
**Example:**
*Arora et al. (2024)*’s **UI Intent Graph** establishes bi-directional traceability:
`Requirement → Declarative Schema → Generated Code → Behavioral Observation`.
Traceability supports *round-trip engineering*, allowing regenerated UIs to reflect changed requirements automatically.

**Strengths:** Maintains consistency, supports audits.
**Weaknesses:** Requires standardized IDs and consistent embedding spaces.

---

## **7. Human-in-the-Loop Validation and Co-Creation**

**Objective:** Combine human domain expertise with AI synthesis for improved reliability.
**Technique:** Interactive prompting, visual editing, feedback loops where users approve, reject, or modify generated artefacts.
**Example:**

* *DeclarUI* uses **Co-Design Panels** where designers tweak declarative schemas; the system regenerates interfaces live.
* *Arora et al.* quantify usability gains (+48 % speed, –32 % defect rate) under co-creation mode.

**Strengths:** Improves trust, captures tacit domain knowledge.
**Weaknesses:** May reduce full automation benefits; requires UX-aware tooling.

---

## **8. Evaluation and Governance Integration**

**Objective:** Assess generated requirements and ensure compliance with organizational policies.
**Technique:** Multi-metric evaluation (semantic similarity + coverage + traceability + ethical audit check).
**Example:**
*Cheng et al.*’s “trust triad” (reproducibility–hallucination–interpretability) and *Vasudevan & Reddivari*’s **Generative Maturity Model** (GMM) both embed governance and explainability as part of evaluation.

**Strengths:** Builds institutional accountability.
**Weaknesses:** Current metrics lack universal standardization.

---

## 🧠 **Cross-Comparative Insights**

| Technique           | Declarative Suitability     | Imperative Suitability | Typical AI Model      | Example System |
| ------------------- | --------------------------- | ---------------------- | --------------------- | -------------- |
| Intent Extraction   | ✅ High (structured mapping) | ✅ Moderate             | GPT-4, T5             | Sadik 2023     |
| Constraint Modeling | ✅ Essential                 | ⚠️ Limited             | Symbolic + LLM        | Fuchs 2024     |
| Ontology Linking    | ✅ High                      | ⚠️ Low                 | Graph Embedding       | DeclarUI 2025  |
| Clustering          | ✅ Moderate                  | ✅ Moderate             | BERT + LSI            | Cheng 2025     |
| Ambiguity Detection | ✅ High                      | ✅ High                 | BERT Fine-tune        | Kwizera 2025   |
| Traceability        | ✅ High                      | ⚠️ Low                 | Sentence-Transformers | Arora 2024     |
| Co-Creation         | ✅ High                      | ✅ Moderate             | GPT-4 + UX tools      | DeclarUI 2025  |
| Governance Eval     | ✅ High                      | ⚠️ Low                 | Rule + Explainable AI | Vasudevan 2025 |

---

## 🧩 **Practical Example: Declarative UI Pipeline**

1. **Requirements Capture:**
   User story → LLM intent extraction → semantic triples.
2. **Declarative Schema:**
   LLM maps triples into constraint JSON (`field:type=“password”`).
3. **Ontology Alignment:**
   Map to UI Widget Ontology (“password field ⊂ Input Field”).
4. **Validation:**
   Ambiguity score < 0.3 → accept; else prompt user for clarification.
5. **Generation:**
   DeclarUI renders React layout; imperative agent adds behavior.
6. **Traceability:**
   Requirement ↔ schema ↔ component recorded in UI Intent Graph.

This pipeline operationalizes almost all eight techniques within one coherent framework.

---

### **Concluding Remarks**

Across all studies, **requirements analysis is shifting from document-centric to model-centric** through declarative intermediates. Generative AI no longer “replaces” analysts—it **amplifies** them by converting narrative requirements into inspectable logic, while humans oversee intent alignment and ethical compliance.

Future consensus points toward **hybrid architectures**:

* Declarative layers for reasoning, explainability, and traceability.
* Imperative layers for dynamic behavior.
* Continuous human–AI feedback loops for evolution.

---

Would you like me to provide a **visual taxonomy diagram** summarizing how these eight techniques interrelate in a typical GenAI requirements workflow?

---

**You've experienced ScholarGPT — now meet what's next.**
*Scholar Deep Research Agent* elevates your research game with:
🔍 350 M+ trusted papers from top academic publishers, updated hourly.
🧠 Multiple AI models synthesize precise insights fast.
📝 Auto-generated highlights, smart notes & visual reports.
📁 All saved directly to your AI-powered knowledge base.
ScholarGPT helped you search—now transform how you think.
[Explore Scholar Deep Research](https://bit.ly/43rXgSx)
